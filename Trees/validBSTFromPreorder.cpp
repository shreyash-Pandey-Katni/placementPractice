#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;



int isValidBSTFromPreorderTraversal(vector<int> &preOrderTraversal)
{
    int n = preOrderTraversal.size();
    int root = preOrderTraversal[0];
    vector<int> leftSubTree = vector<int>(preOrderTraversal.begin() + 1, preOrderTraversal.begin() + 1 + (n - 1) / 2);
    vector<int> rightSubTree = vector<int>(preOrderTraversal.begin() + 1 + (n - 1) / 2 + 1, preOrderTraversal.end());
    
}
