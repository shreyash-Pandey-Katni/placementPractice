#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

unordered_map<int, pair<int, int>> m;
int leftHd = 0;
int rightHd = 0;

void bottomViewUtil(Node *root, int hd, int level)
{
    if (root == NULL)
        return;
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(level, root->data);
    }
    else
    {
        if (m[hd].first < level)
        {
            m[hd] = make_pair(level, root->data);
        }
    }
    leftHd = min(leftHd, hd);
    rightHd = max(rightHd, hd);
    bottomViewUtil(root->left, hd - 1, level + 1);
    bottomViewUtil(root->right, hd + 1, level + 1);
}

vector<int> bottomView(Node *root)
{
    vector<int> v;
    if (root == NULL)
        return v;
    bottomViewUtil(root, 0, 0);
    int i = leftHd;
    while (i <= rightHd)
    {
        v.push_back(m[i].second);
        i++;
    }
    return v;
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
    vector<int> v = bottomView(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
