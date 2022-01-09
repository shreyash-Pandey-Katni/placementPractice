#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
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
// bool leftToRight = false;

// vector<int> result;

// void zigZagTraversalUtil(Node *root, int level, int leftToRight){
//     if(root == NULL)
//         return;
//     if(root->left == NULL && root->right == NULL){
//         result.push_back(root->data);
//         return;
//     }
//     if(leftToRight){
//         zigZagTraversalUtil(root->left, level-1, leftToRight);
//         zigZagTraversalUtil(root->right, level-1, leftToRight);
//     }
//     else{
//         zigZagTraversalUtil(root->right, level-1, leftToRight);
//         zigZagTraversalUtil(root->left, level-1, leftToRight);
//     }
// }

vector<vector<int>> result;

void zigZagTraversalUtil(Node *root, int level, bool leftToRight){
    if(root == NULL)
        return;
    if(result.size() == level){
        vector<int> temp;
        result.push_back(temp);
    }
    if(leftToRight)
        result[level].push_back(root->data);
    else
        result[level].insert(result[level].begin(), root->data);
    zigZagTraversalUtil(root->left, level+1, !leftToRight);
    zigZagTraversalUtil(root->right, level+1, !leftToRight);
}

vector<int> zigZagTraversal(Node *root)
{
    zigZagTraversalUtil(root, 0, true);
    vector<int> resultOneDimensional;
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            resultOneDimensional.push_back(result[i][j]);
        }
    }
    return resultOneDimensional;
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
    vector<int> resultMain = zigZagTraversal(root);
    for (int i = 0; i < resultMain.size(); i++)
    {
        cout << resultMain[i] << " ";
    }
    return 0;
}
