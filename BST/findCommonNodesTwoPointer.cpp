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

vector<int> inOrderTraversal(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    vector<int> left = inOrderTraversal(root->left);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back(root->data);
    vector<int> right = inOrderTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

vector<int> findCommon(Node* root1, Node* root2){
    vector<int> ans;
    vector<int> inOrder1 = inOrderTraversal(root1);
    vector<int> inOrder2 = inOrderTraversal(root2);
    int i = 0, j = 0;
    while(i < inOrder1.size() && j < inOrder2.size()){
        if(inOrder1[i] == inOrder2[j]){
            ans.push_back(inOrder1[i]);
            i++;
            j++;
        }
        else if(inOrder1[i] < inOrder2[j])
            i++;
        else
            j++;
    }
    return ans;
}