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
vector<vector<int>> temp;

void reverseLevelOrderUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(temp.size() <= level)
        temp.push_back(vector<int>());
    temp[level].push_back(root->data);
    reverseLevelOrderUtil(root->right, level + 1);
    reverseLevelOrderUtil(root->left, level + 1);
}


vector<int> reverseLevelOrder(Node *root)
{
    if(root == NULL)
        return vector<int>();
    temp.clear();
    reverseLevelOrderUtil(root, 0);
    vector<int> finalResult;
    for(int i = temp.size() - 1; i >= 0; i--){
        for (int j = temp[0].size() - 1; j >= 0; j--)
        {
            finalResult.push_back(temp[i][j]);
        }        
    }
    return finalResult;
}