#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}

vector<Node *> temp;

void convertToDLLUtil(Node *root)
{
    if (root == NULL)
        return;
    if (isLeaf(root->right))
    {
        temp.push_back(root->right);
        root->right = NULL;
    }
    if (isLeaf(root->left))
    {
        temp.push_back(root->left);
        root->left = NULL;
    }

    convertToDLLUtil(root->right);
    convertToDLLUtil(root->left);
}

Node *bToDLL(Node *root)
{
    temp.clear();
    if (root == NULL)
        return NULL;
    convertToDLLUtil(root);
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        if(i == 0){
            temp[i]->right = NULL;
            temp[i]->left = temp[i+1];
        }
        else if(i == temp.size() - 1){
            temp[i]->right = temp[i-1];
            temp[i]->left = NULL;
        }
        else{
            temp[i]->right = temp[i-1];
            temp[i]->left = temp[i+1];
        }
    }
    return temp.back();
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
    Node *head = bToDLL(root);
    inorder(root);
    cout << endl;
    Node *tail = head;
    while (head != NULL)
    {
        cout << head->val << " ";
        tail = head;
        head = head->right;
    }
    cout << endl;
    while (tail != NULL)
    {
        cout << tail->val << " ";
        tail = tail->left;
    }
    return 0;
}
