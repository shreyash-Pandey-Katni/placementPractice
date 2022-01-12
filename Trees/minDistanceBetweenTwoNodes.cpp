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
vector<int> n1Ancestors;
vector<int> n2Ancestors;
void lcaUtil(Node* root, int target, vector<int> path, bool isN1){
    if(root == NULL)
        return;
    if(root->data == target){
        path.push_back(root->data);
        isN1 ? n1Ancestors = path: n2Ancestors = path;
        return;
    }
    path.push_back(root->data);
    lcaUtil(root->left, target, path, isN1);
    lcaUtil(root->right, target, path, isN1);
    path.pop_back();
}
int findDist(Node* root, int a,int b){
    if(root == NULL){
        return -1;
    }
    lcaUtil(root, a, vector<int>(), true);
    lcaUtil(root, b, vector<int>(), false);
    int i = min(n1Ancestors.size(), n2Ancestors.size())-1;
    while(i >= 0){
        if(n1Ancestors[i] == n2Ancestors[i])
            break;
        i--;
    }
    return n1Ancestors.size() - 1 + n2Ancestors.size() - 1 - 2*i;
}