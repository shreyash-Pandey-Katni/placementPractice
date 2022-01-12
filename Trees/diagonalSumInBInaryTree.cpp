#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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
// unordered_map<int, int> hash;
vector<int> sumVector;
void diagonalSumUtil(Node *node, int level){
    if(node == NULL)
        return;
    if(sumVector.size() <= level)
        sumVector.push_back(node->data);
    else
        sumVector[level] += node->data;
    diagonalSumUtil(node->left, level + 1);
    diagonalSumUtil(node->right, level);
}
vector<int> diagonalSum(Node *root)
{
    sumVector.clear();
    diagonalSumUtil(root, 0);
    reverse(sumVector.begin(), sumVector.end());
    return sumVector;
}