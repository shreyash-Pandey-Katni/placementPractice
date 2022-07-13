n = int(input())
numArray = []
for i in range(n):
    numArray.append(int(input()))

temp = [None] * n
i = 0
j = n-1
index = 0
while(i <= j):
    temp[index] = numArray[j]
    index += 1
    if index == n:
        break
    temp[index] = numArray[i]
    index += 1
    i += 1
    j -= 1

# for i in range(1,n,2):
#     temp[int(i/2)] = numArray[i]

# for i in range(0,n,2):
#     temp[n-1-int(i/2)] = numArray[i]

mod = 10**9 + 7

hashValue = 0
for i in range(n):
    hashValue += temp[i]*(10**(i+1)) % mod

print(hashValue)
