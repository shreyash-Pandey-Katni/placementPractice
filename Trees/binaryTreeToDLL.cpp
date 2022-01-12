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
Node* bToDLLLeft(Node* root){
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        return root;
    Node* left = bToDLLLeft(root->left);
    Node* right = bToDLLLeft(root->right);
    Node* temp = left;
    if(left != NULL){
        while(temp->right != NULL)
            temp = temp->right;
        temp->right = root;
        root->left = temp;
    }
    root->right = right;
    return left==NULL?root:left;
}
Node* bToDLLRight(Node* root){
    if(root == NULL)
        return NULL;
    Node* prev = NULL;
    Node* curr = root;
    while(curr != NULL){
        curr->left = prev;
        prev = curr;
        curr = curr->right;
    }
    return root;
}
Node* bToDLL(Node* root){
    if(root == NULL)
        return NULL;
    Node* left = bToDLLLeft(root);
    Node* right = bToDLLRight(left);
    return right;
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
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->left;
    }
    return 0;
}
