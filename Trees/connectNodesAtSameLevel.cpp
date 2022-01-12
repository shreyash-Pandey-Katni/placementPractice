#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right, *nextRight;
    
    Node(int x){
        data = x;
        left = right = nextRight = NULL;
    }
};
vector<vector<Node *>> temp;

void connectUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(temp.size() == level)
        temp.push_back(vector<Node *>());
    else
        temp[level][temp[level].size()-1]->nextRight = root;
    temp[level].push_back(root);
    connectUtil(root->left, level+1);
    connectUtil(root->right, level+1);
}

void connect(Node *root){
    if(root == NULL)
        return;
    connectUtil(root, 0);
}