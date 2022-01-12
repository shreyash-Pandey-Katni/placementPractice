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



Node* LCAUtil(Node* root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->data>=n1 && root->data<=n2)
        return root;
    Node* left = LCAUtil(root->left, n1, n2);
    Node* right = LCAUtil(root->right, n1, n2);
    if(left != NULL && right != NULL)
        return root;
    return left != NULL?left:right;
}

Node* LCA(Node* root, int n1, int n2){
    int low = min(n1, n2);
    int high = max(n1, n2);
    return LCAUtil(root, low, high);
}

Node* buildBinarySearchTree(string s){
    if(s.length() == 0 || s[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(s);
    for(string str; iss >> str;){
        ip.push_back(str);
    }
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i<ip.size()){
        Node* currNode = q.front();
        q.pop();
        string curr = ip[i];
        if(curr != "N"){
            currNode->left = new Node(stoi(curr));
            q.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        curr = ip[i];
        if(curr != "N"){
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
    Node* root = buildBinarySearchTree(s);
    int n1, n2;
    cin >> n1 >> n2;
    Node* ans = LCAUtil(root, n1, n2);
    cout << ans->data << endl;
    return 0;
}
