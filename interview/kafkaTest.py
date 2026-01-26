import asyncio
from confluent_kafka import Consumer, KafkaException, KafkaError
from time import time
from mysql import connector

BATCH_SIZE = 500
PAUSE_THRESOLD = 5000
RESUME_THRESOLD = 2000

buffer = []

consumerConfiguration = {
    "bootstrap.servers":"kafka server url",
    "group.id":"vector-consumers",
    "enable.auto.commit":False,
    "auto.offset.reset":"earliest",
    "enable.partition.eof":False
}

consumer = Consumer(consumerConfiguration)
consumer.subscribe(["vector.updates", "vectors.metadata"])

connection = connector.connect(
    host="mysql host url",
    user="username",
    password="password",
    database="vectors"
)

async def dbWrite(batch):
    # Mysql insert logic here
    cursor = connection.cursor()
    insert_query = "INSERT INTO vectors_table (vector_id, vector_data) VALUES (%s, %s)"
    cursor.executemany(insert_query, batch)
    connection.commit()
    cursor.close()
    await asyncio.sleep(0.01)  # Yield control to the event loop
    return

def handleMessage(msg):
    global buffer
    payload = msg.value()
    buffer.append((msg.topic(), payload))

async def consumerLoop():
    paused = False
    lastCommit = time()
    while True:
        msg = consumer.poll(timeout=0)
        if msg is None:
            await asyncio.sleep(0.001)
            continue
        if msg.error():
            if msg.error().code() != KafkaError._PARTITION_EOF:
                print("Error:", msg.error())
            continue
        handleMessage(msg=msg)
        if len(buffer)>PAUSE_THRESOLD and not paused:
            print("Pausing paritions due to high watermark")
            consumer.pause(consumer.assignment())
            paused = True
        elif len(buffer) < RESUME_THRESOLD and paused:
            print("Resume paritioning")
            consumer.resume(consumer.assignment())
            paused = False
        
        if len(buffer) >= BATCH_SIZE:
            batch = buffer[:BATCH_SIZE]
            del buffer[:BATCH_SIZE]
            await dbWrite(batch=batch)
        
        if time() - lastCommit >2:
            consumer.commit(asynchronous=True)
            lastCommit = time()
        
async def main():
    try:
        await consumerLoop()
    finally:
        consumer.close()

if __name__=="__main__":
    asyncio.run(main())