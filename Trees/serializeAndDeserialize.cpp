#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> serialize(Node *root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            ans.push_back(-1);
            continue;
        }
        ans.push_back(temp->data);
        q.push(temp->left);
        q.push(temp->right);
    }
    return ans;
}

Node * deserialize(vector<int> &arr){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(arr[i] != -1){
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(arr[i] != -1){
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}