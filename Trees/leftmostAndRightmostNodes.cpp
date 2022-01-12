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
void printCorner(Node *root){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                cout<<endl;
                if(!q.empty())
                    q.push(NULL);
                continue;
            }
            if(i == 0 || i == size-1)
                cout<<temp->data<<" ";
            // cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
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
    printCorner(root);
    return 0;
}
