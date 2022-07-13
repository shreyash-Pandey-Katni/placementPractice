#include <bits/stdc++.h>
using namespace std;
// you are given a string S of length N, Q ranges of the form [a,b] where a and b are indices of the string, and a permutation arr containing number from 1 to N.
// you have to determine the minimum number of operations for the remaining string to be a good string.
// a good string is considered good if all the Q ranges have all distinct characters in them. Removed characters are not considered good.
// if the string is not good, you have to determine the minimum number of operations required to make it good.
// if the string is already good, you have to print 0.
// input:
// S = "abcd"
// Q = [[1,2],[2,3],[3,4]]
// ranges are [1,2],[2,3],[3,4]
// arr = [1,2,3,4]
// output:
// 2

int cntDistinct(string str)
{
    unordered_set<char> s;
    int countUnderScore = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '_')
        {
            countUnderScore++;
            continue;
        }
        s.insert(str[i]);
    }
    return str.size() - s.size() - countUnderScore;
}

bool isGood(string str, vector<vector<int>> ranges)
{
    for (int i = 0; i < ranges.size(); i++)
    {
        // if(ranges[i][0] == ranges[i][1]){
        //     return false;
        // }
        string temp = str.substr(ranges[i][0] - 1, ranges[i][1] == ranges[i][0] ? 1 : ranges[i][1] - ranges[i][0] + 1);
        if (cntDistinct(temp) != 0)
        {
            return false;
        }
    }
    return true;
}

int goodString(int N, int Q, string S, vector<int> arr, vector<vector<int>> ranges)
{
    int minPermutation = 0;
    int i = 0;
    for (; i < N; i++)
    {
        S[arr[i] - 1] = '_';
        if (isGood(S, ranges))
        {
            break;
        }
    }
    if (i == N || i == 0)
    {
        return 0;
    }
    return i + 1;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int Q;
        cin >> Q;
        string S;
        cin >> S;
        vector<int> arr(N);
        for (int i_arr = 0; i_arr < N; i_arr++)
        {
            cin >> arr[i_arr];
        }
        vector<vector<int>> ranges(Q, vector<int>(2));
        for (int i_ranges = 0; i_ranges < Q; i_ranges++)
        {
            for (int j_ranges = 0; j_ranges < 2; j_ranges++)
            {
                cin >> ranges[i_ranges][j_ranges];
            }
        }

        int out_;
        out_ = goodString(N, Q, S, arr, ranges);
        cout << out_;
        cout << "\n";
    }
}