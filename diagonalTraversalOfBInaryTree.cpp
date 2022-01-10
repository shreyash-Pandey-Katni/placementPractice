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
vector<vector<int>> temp;
void diagonalUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(temp.size() == level){
        vector<int> v;
        temp.push_back(v);
    }
    temp[level].push_back(root->data);
    diagonalUtil(root->left, level+1);
    diagonalUtil(root->right, level);
}

vector<int> diagonal(Node *root)
{
    if(root == NULL)
        return vector<int>();
    diagonalUtil(root, 0);
    vector<int> result;
    for(int i = 0; i < temp.size(); i++)
    {
        for(int j = 0; j < temp[i].size(); j++)
        {
            result.push_back(temp[i][j]);
        }
    }
    return result;
}