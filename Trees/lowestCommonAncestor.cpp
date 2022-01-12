#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
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
vector<int> n1Ancestors;
vector<int> n2Ancestors;

void lcaUtil(Node* root, int target, vector<int> path, bool isN1){
    if(root == NULL)
        return;
    if(root->data == target){
        path.push_back(root->data);
        isN1 ? n1Ancestors = path: n2Ancestors = path;
        return;
    }
    path.push_back(root->data);
    lcaUtil(root->left, target, path, isN1);
    lcaUtil(root->right, target, path, isN1);
    path.pop_back();
}

Node* lca(Node* root, int n1, int n2){
    if(root == NULL)
        return NULL;
    vector<int> path;
    lcaUtil(root, n1, path, true);
    lcaUtil(root, n2, path, false);
    int i = min(n1Ancestors.size(), n2Ancestors.size())-1;
    while(i >= 0){
        if(n1Ancestors[i] == n2Ancestors[i])
            break;
        i--;
    }
    return new Node(n1Ancestors[i]);
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
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Node *lcaNode = lca(root, n1, n2);
    cout << lcaNode->data << endl;
    return 0;
}
