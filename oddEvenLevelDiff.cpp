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

int oddLevelSum = 0;
int evenLevelSum = 0;

void summation(Node *root, int level){
    if(root == NULL)
        return;
    if(level % 2 == 0){
        oddLevelSum += root->data;
    }
    else{
        evenLevelSum += root->data;
    }
    summation(root->left, level + 1);
    summation(root->right, level + 1);
}

int getLevelDiff(Node *root){
    if(root == NULL)
        return 0;
    oddLevelSum = 0;
    evenLevelSum = 0;
    summation(root, 0);
    return oddLevelSum - evenLevelSum;
}