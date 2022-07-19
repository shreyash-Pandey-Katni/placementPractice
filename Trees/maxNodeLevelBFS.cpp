#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
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

int maxNodeLevel(Node *root){
    if(root == NULL){
        return 0;
    }
    int maxLevel = 0;
    int currLevel = 0;
    list<Node*> q;
    q.push_back(root);
    q.push_back(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop_front();
        if(temp == NULL){
            if(!q.empty()){
                q.push_back(NULL);
                currLevel++;
            }
        }
        else{
            if(temp->left){
                q.push_back(temp->left);
            }
            if(temp->right){
                q.push_back(temp->right);
            }
        }
        if(q.empty()){
            maxLevel = max(maxLevel, currLevel);
        }
    }
    return maxLevel;
}