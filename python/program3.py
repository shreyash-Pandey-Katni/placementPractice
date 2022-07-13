import pandas as pd
import math


class Node(object):
    def __init__(self, label):
        self.label = label
        self.branches = []


def entropy(data):
    en = 0
    totalLength = data.shape[-1]
    pLength = data[data['play'] == 'Yes'].shape[-1]
    nLength = data[data['play'] == 'No'].shape[-1]
    if pLength > 0:
        en -= (pLength/totalLength)*math.log2(pLength/totalLength)
    if nLength > 0:
        en -= (nLength/totalLength)*math.log2(nLength/totalLength)
    return en


def gain(data, attribute_g, entropy_g):
    values = set(data[attribute_g])
    gain_g = entropy_g
    for value in values:
        gain_g -= (len(data.loc[data[attribute_g] == value]) /
                   data.shape[-1])*entropy(data[data[attribute_g] == value])
    return gain_g


def get_attribute(data):
    maxGain = 0
    entropyGetAttribute = entropy(data)
    attribute = ""
    for attr in data.columns[:-1]:
        g = gain(data, attr, entropyGetAttribute)
        if g > maxGain:
            maxGain = g
            attribute = attr
    return attribute


def decision_tree(data):
    root = Node("NULL")
    entropyDecisionTree = entropy(data)
    if entropyDecisionTree == 0:
        if len(data.loc[data[data.columns[-1]] == 'Yes']) == len(data):
            root.label = 'Yes'
        else:
            root.label = 'No'
        return root
    if data.shape[-1] == 1:
        return
    else:
        attributeDecisionTree = get_attribute(data)
        root.label = attributeDecisionTree
        values = set(data[attributeDecisionTree])
        for value in values:
            root.branches[value] = decision_tree(
                data[data[attributeDecisionTree] == value].drop(attributeDecisionTree, axis=1))
    return root


def get_rules(root, rule, rules):
    if not root.branches:
        rules.append(rule[:-1] + "=>" + root.label)
        return rules
    for val in root.branches:
        get_rules(root.branches[val], rule +
                  root.label+"="+str(val) + "^", rules)
    return rules


def test(tree, test_str):
    if not tree.branches:
        return tree.label
    print(str(test_str[tree.label]), tree.label, test_str)
    return test(tree.branch[str(test_str[tree.label])], test_str)


data = pd.read_csv("tennis.csv")
tree = decision_tree(data)
rules = get_rules(tree, "", [])
for rule in rules:
    print(rule)

testStr = {}
print("Test case input:")
for attr in data.columns[:-1]:
    testStr[attr] = input(attr+":")
print(testStr)
print(test(tree, testStr))
