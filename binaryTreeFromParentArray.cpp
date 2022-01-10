#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node *createTree(int parent[], int n){
    vector<Node *> v;
    for(int i=0; i<n; i++)
    {
        Node *temp = new Node(i);
        v.push_back(temp);
    }
    Node *root;
    for(int i=0; i<n; i++)
    {
        if(parent[i] == -1)
            root = v[i];
        else if(v[parent[i]]->left == NULL)
            v[parent[i]]->left = v[i];
        else
            v[parent[i]]->right = v[i];
    }
    return root;
}