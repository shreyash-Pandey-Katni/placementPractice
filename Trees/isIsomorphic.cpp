#include<iostream>
#include<vector>
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
bool isMirror(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->left == root2->right){
        Node* temp = root1->left;
        root1->left = root1->right;
        root1->right = temp;
    }
    return (root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}
bool isIsomorphic(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) || (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left)));
}