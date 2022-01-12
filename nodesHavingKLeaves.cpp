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
vector<int> ans;

bool isLeaf(Node *root){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int numOfLeaves(Node *root, int k){
    if(root == NULL)
        return 0;
    if(isLeaf(root)){
        return 1;
    }
    int total = numOfLeaves(root->left, k) + numOfLeaves(root->right, k);
    if(total == k){
        ans.push_back(root->data);
    }
    return total;
}
vector<int> btWithKleaves(Node *ptr, int k)
{
    ans.clear();
    int leaves = numOfLeaves(ptr, k);
    if(leaves == k)
        ans.insert(ans.begin(), ptr->data);
    return ans.empty() ? vector<int>{-1} : ans;
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
    int target;
    cin >> target;
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    vector<int> ans = btWithKleaves(root, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
