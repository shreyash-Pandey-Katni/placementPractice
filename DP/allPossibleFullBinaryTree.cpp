#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

vector<TreeNode *> helper(int n){
    if(n == 1){
        return vector<TreeNode *>{new TreeNode(0)};
    }
    vector<TreeNode *> result;
    for (int i = 1; i < n;i +=2){
        vector<TreeNode *> left = helper(i);
        vector<TreeNode *> right = helper(n-i-1);
        for (auto l : left){
            for (auto r : right){
                TreeNode *root = new TreeNode(0);
                root->left = l;
                root->right = r;
                // vector<TreeNode *> result;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode *> allPossibleFBT(int n)
{
    if (n % 2 == 0)
        return {};
    return helper(n);
}