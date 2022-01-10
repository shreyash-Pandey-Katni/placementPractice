#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void convert(Node *head, TreeNode *&root)
{
    if(head == NULL)
        return;
    queue<Node*> q;
    q.push(head->next);
    queue<TreeNode*> unfilledQueue;
    root = new TreeNode(head->data);
    TreeNode *treeNodeTemp;
    TreeNode *currTreeNode = root;
    unfilledQueue.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        treeNodeTemp = new TreeNode(temp->data);
        unfilledQueue.push(treeNodeTemp);
        currTreeNode = unfilledQueue.front();
        if(currTreeNode != NULL && (currTreeNode->left==NULL || currTreeNode->right==NULL))
        {
            if(currTreeNode->left==NULL)
            {
                currTreeNode->left = treeNodeTemp;
            }
            else
            {
                currTreeNode->right = treeNodeTemp;
                unfilledQueue.pop();
            }
        }
        if(temp->next != NULL)
            q.push(temp->next);
        
    }
}

vector<int> inorder(TreeNode *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (head == NULL)
        {
            head = new Node(x);
            temp = head;
        }
        else
        {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }
    TreeNode *root;
    convert(head, root);
    vector<int> ans = inorder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
