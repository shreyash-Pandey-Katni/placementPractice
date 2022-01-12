#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
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

unordered_map<int, int> m;
int maxVal = INT_MIN;
int maxValLevel = 0;
int maxNodeLevelUtil(Node *root, int level){
    if(root == NULL){
        return level;
    }
    if(m.find(level) == m.end()){
        m[level] = 1;
    }
    else{
        m[level] += 1;
        if(m[level] > maxVal){
            maxVal = m[level];
            maxValLevel = level;
        }
    }
    maxNodeLevelUtil(root->left, level + 1);
    maxNodeLevelUtil(root->right, level + 1);
    return maxValLevel;
}
int maxNodeLevel(Node *root)
{
    if(root == NULL){
        return 0;
    }
    return maxNodeLevelUtil(root, 0);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(9);
    root->left = new Node(10);
    root->right = new Node(5);
    cout << maxNodeLevel(root) << endl;
    return 0;
}
