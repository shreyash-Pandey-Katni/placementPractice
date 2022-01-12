#include<iostream>
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
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    return root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}