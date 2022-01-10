#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> leftBoundary;
vector<int> rightBoundary;
vector<int> leafNodes;
bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void leftBoundaryUtil(Node *root)
{
    if (root == NULL)
        return;
    if (!isLeaf(root))
        leftBoundary.push_back(root->data);
    if(root->left)
        leftBoundaryUtil(root->left);
    else if (root->right)
        leftBoundaryUtil(root->right);    
}
void rightBoundaryUtil(Node *root)
{
    if (root == NULL)
        return;
    if(root->right)
        rightBoundaryUtil(root->right);
    else if (root->left)
        rightBoundaryUtil(root->left);
    if(!isLeaf(root))
        rightBoundary.push_back(root->data);
    // rightBoundary.push_back(root->data);
}
void leafNodesUtil(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        leafNodes.push_back(root->data);
    leafNodesUtil(root->left);
    leafNodesUtil(root->right);
}
vector<int> boundary(Node *root)
{
    if (root == NULL)
        return vector<int>();
    leftBoundaryUtil(root->left);
    rightBoundaryUtil(root->right);
    leafNodesUtil(root);
    vector<int> result{root->data};
    for (int i = 0; i < leftBoundary.size(); i++)
        result.push_back(leftBoundary[i]);
    for (int i = 0; i < leafNodes.size(); i++)
        result.push_back(leafNodes[i]);
    for (int i = 0; i <rightBoundary.size(); i++)
        result.push_back(rightBoundary[i]);
    return result;
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
    vector<int> result = boundary(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
