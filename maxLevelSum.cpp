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
vector<int> temp;
void maxLevelSumUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(level == temp.size()){
        temp.push_back(root->data);
    }
    else{
        temp[level] += root->data;
    }
    maxLevelSumUtil(root->left, level + 1);
    maxLevelSumUtil(root->right, level + 1);
}
int maxLevelSum(Node *root){
    temp.clear();
    maxLevelSumUtil(root, 0);
    int max = INT_MIN;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] > max)
            max = temp[i];
    }
    return max;
}