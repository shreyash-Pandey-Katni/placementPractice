import pandas as pd

data = pd.read_csv('tennis.csv')

te = data.shape[0]
np = data[data[data.columns[-1]] == 'Yes'].shape[0]
nn = te - np

training = data.sample(frac=0.75, replace=False)
test = pd.concat([data, training]).drop_duplicates(keep=False)

print("Training Dataset:", training)
print("Test Dataset:", test)

prob = {}

for col in data.columns[:-1]:
    prob[col] = {}
    vals = set(data[col])
    for val in vals:
        temp = data[data[col] == val]
        pe = temp[temp[temp.columns[-1]] == 'Yes'].shape[-1]
        ne = len(temp) - pe
        prob[col][val] = [pe/np, ne/nn]
prediction = []
rightPrediction = 0
for row in test:
    # row = test.iloc[i]
    fpp = np/te
    fpn = nn/te
    for col in test.columns[:-1]:
        fpp *= prob[col][row[col]][0]
        fpn *= prob[col][row[col]][1]
    if fpp > fpn:
        prediction.append('Yes')
    else:
        prediction.append('No')
    if prediction[-1] == row[-1]:
        rightPrediction += 1
