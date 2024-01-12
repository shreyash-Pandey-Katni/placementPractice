#include <iostream>
#include <string>
using namespace std;

int lcsRecursive(string X, string Y, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(X[n-1] == Y[m-1])
    return 1+ lcsRecursive(X, Y, n-1, m-1);
    else
    return max(lcsRecursive(X, Y, n-1,m), lcsRecursive(X,Y, n, m-1));
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int n = X.size();
    int m = Y.size();

    cout << "Length of LCS is " << lcsRecursive(X, Y, n, m) << endl;

    return 0;
}