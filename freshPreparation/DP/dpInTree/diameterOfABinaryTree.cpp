#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int diameter(Node *root, int &res){
    if(root == NULL)
    return 0;
    int left = diameter(root->left, res);
    int right = diameter(root->right, res);
    int temp = 1 + max(left, right);
    int ans = max(temp, 1+left+right);
    res = max(res, ans);
    return temp;
}

int diameter(Node *root)
{
    if(root == NULL)
    return 0;
    int res = INT_MIN;
    diameter(root, res);
    return res;
}

int main()
{
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculate the diameter of the binary tree
    int result = diameter(root);

    // Print the result
    cout << "Diameter of the binary tree: " << result << endl;

    // Clean up the memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
