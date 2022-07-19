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

Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    Node* root = new Node(str[0]);
    string left = str.substr(2);
    string right = str.substr(3);
    root->left = buildTree(left);
    root->right = buildTree(right);
    return root;
}

int maxNodeLevelUtil(Node *root, int level, unordered_map<int, int> &m, int &maxVal, int &maxValLevel)
{
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
    maxNodeLevelUtil(root->left, level + 1, m, maxVal, maxValLevel);
    maxNodeLevelUtil(root->right, level + 1, m, maxVal, maxValLevel);
    return maxValLevel;
}
int maxNodeLevel(Node *root)
{
    int maxVal = 1;
    int maxValLevel = 0;
    unordered_map<int, int> m = unordered_map<int, int>();
    if(root == NULL){
        return 0;
    }
    return maxNodeLevelUtil(root, 0, m, maxVal, maxValLevel);
}

int main(int argc, char const *argv[])
{

    Node *root = buildTree("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16");
    cout << maxNodeLevel(root) << endl;
    return 0;
}
