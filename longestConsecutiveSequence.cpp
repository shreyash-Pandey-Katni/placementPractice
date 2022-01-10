#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
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

int length = 1;
int maxLength = 1;

bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}

void longestConsecutiveSequenceUtil(Node *root, int pathLength)
{
    if (root == NULL)
        return;
    maxLength = max(maxLength, pathLength);
    if (isLeaf(root))
    {
        return;
    }
    if (root->left != NULL && root->left->data - 1 == root->data)
        longestConsecutiveSequenceUtil(root->left, pathLength + 1);
    else
        longestConsecutiveSequenceUtil(root->left, 1);
    if (root->right != NULL && root->right->data - 1 == root->data)
        longestConsecutiveSequenceUtil(root->right, pathLength + 1);
    else
        longestConsecutiveSequenceUtil(root->right, 1);
}

int longestConsecutive(Node *root)
{
    if (root == NULL)
        return 0;
    longestConsecutiveSequenceUtil(root, 1);
    return maxLength;
}

Node *buildTree(string s)
{
    if (s.length() == 0)
    {
        return NULL;
    }
    vector<string> ip;
    istringstream iss(s);
    for (string str; iss >> str;)
    {
        ip.push_back(str);
    }
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < ip.size())
    {
        Node *currNode = q.front();
        q.pop();
        string curr = ip[i];
        if (curr != "N")
        {
            currNode->left = new Node(stoi(curr));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
        {
            break;
        }
        curr = ip[i];
        if (curr != "N")
        {
            currNode->right = new Node(stoi(curr));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    cout << longestConsecutive(root);
    return 0;
}
