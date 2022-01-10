#include<iostream>
#include<vector>
#include<algorithm>
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
vector<int> noSiblingUtil(Node* root){
    vector<int> result;
    if(root == NULL)
        return result;
    if(root->left == NULL && root->right == NULL){
        // result.push_back(root->data);
        return result;
    }
    if(root->left == NULL && root->right != NULL){
        result.push_back(root->right->data);
        // return result;
    }
    if(root->left != NULL && root->right == NULL){
        result.push_back(root->left->data);
        // return result;
    }
    vector<int> left = noSiblingUtil(root->left);
    vector<int> right = noSiblingUtil(root->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
vector<int> noSibling(Node *root){
    vector<int> result;
    if(root == NULL)
        return result;
    result = noSiblingUtil(root);
    sort(result.begin(), result.end());
    return result.size() == 0 ? vector<int>{-1} : result;
}