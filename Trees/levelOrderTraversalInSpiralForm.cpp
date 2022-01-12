#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
vector<vector<int>> result;

void findSpiralHelper(Node *root, int level, bool leftToRight){
    if(root == NULL)
        return;
    if(result.size() <= level)
        result.push_back(vector<int>());
    if(leftToRight)
        result[level].push_back(root->data);
    else
        result[level].insert(result[level].begin(), root->data);
    findSpiralHelper(root->left, level + 1, !leftToRight);
    findSpiralHelper(root->right, level + 1, !leftToRight);
}

vector<int> findSpiral(Node *root){
    result.clear();
    if(root == NULL)
        return vector<int>();
    vector<int> finalResult;
    findSpiralHelper(root, 0, true);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            finalResult.push_back(result[i][j]);
        }
    }
    return finalResult;
}