#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
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

int levelX = -1;
int levelY = -1;
bool areSiblings = false;

void isCousinsUtil(Node *root, int x, int y, int level)
{
    if (root == NULL)
        return;
    if (root->left != NULL && root->right != NULL)
    {
        if ((root->left->data == x && root->right->data == y) || (root->left->data == y && root->right->data == x))
        {
            areSiblings = true;
            return;
        }
        if (root->left->data == x)
        {
            levelX = level + 1;
        }
        if (root->right->data == y)
        {
            levelY = level + 1;
        }
    }
    if (root->left != NULL)
    {
        if (root->left->data == x)
        {
            levelX = level + 1;
        }
        if (root->left->data == y)
        {
            levelY = level + 1;
        }
    }
    if (root->right != NULL)
    {
        if (root->right->data == x)
        {
            levelX = level + 1;
        }
        if (root->right->data == y)
        {
            levelY = level + 1;
        }
    }
    isCousinsUtil(root->left, x, y, level + 1);
    isCousinsUtil(root->right, x, y, level + 1);
}

bool isCousins(Node *root, int a, int b)
{
    levelX = 0;
    levelY = 0;
    areSiblings = false;
    if (root == NULL)
    {
        return false;
    }
    isCousinsUtil(root, a, b, 0);
    return !areSiblings && levelX == levelY;
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
    int a, b;
    cin >> a >> b;
    if (isCousins(root, a, b))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
