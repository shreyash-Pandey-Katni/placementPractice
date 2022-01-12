#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
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

Node* lca(Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    if(left != NULL && right != NULL)
        return root;
    return left != NULL?left:right;
}

vector<int> pathLeft;
vector<int> pathRight;

void findPathLeft(Node* root, int n1, int n2, vector<int> path, int isLeft){
    if(root == NULL)
        return;
    if(root->data == n1){
        pathLeft = path;
        return;
    }
    if(root->data == n2){
        pathLeft = path;
        return;
    }
    path.push_back(isLeft);
    findPathLeft(root->left, n1, n2, path, 1);
    findPathLeft(root->right, n1, n2, path, 0);
}

void findPathRight(Node* root, int n1, int n2, vector<int> path, int isLeft){
    if(root == NULL)
        return;
    if(root->data == n1){
        pathRight = path;
        return;
    }
    if(root->data == n2){
        pathRight = path;
        return;
    }
    path.push_back(isLeft);
    findPathRight(root->left, n1, n2, path, 1);
    findPathRight(root->right, n1, n2, path, 0);
}

int NumberOFTurns(Node* root, int first, int second){
    if(root == NULL)
        return 0;
    Node* lcaNode = lca(root, first, second);
    vector<int> pathLeftTemp;
    vector<int> pathRightTemp;
    findPathLeft(lcaNode, first, second, pathLeftTemp, 1);
    findPathRight(lcaNode, first, second, pathRightTemp, 0);
    int count = 0;
    if(pathLeft.size()==0){
        for(int i=0;i<pathRight.size()-1;i++){
            if(pathRight[i]!=pathRight[i+1])
                count++;
        }
        return count;
    }
    if(pathRight.size()==0){
        for(int i=0;i<pathLeft.size()-1;i++){
            if(pathLeft[i]!=pathLeft[i+1])
                count++;
        }
        return count;
    }
    for(int i=0;i<pathLeft.size()-1;i++){
        if(pathLeft[i]!=pathLeft[i+1])
            count++;
    }
    for(int i=0;i<pathRight.size()-1;i++){
        if(pathRight[i]!=pathRight[i+1])
            count++;
    }
    return count;
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
int main()
{
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    int first, second;
    cin >> first >> second;
    cout << NumberOFTurns(root, first, second);
    return 0;
}