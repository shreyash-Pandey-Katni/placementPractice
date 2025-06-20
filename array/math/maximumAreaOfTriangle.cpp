#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <map>

using namespace std;
int solve(vector<string> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<int> leftMost(3, INT_MAX);
    vector<int> rightMost(3, INT_MIN);
    vector<vector<int>> topMost(m, vector<int>(3, INT_MAX));
    vector<vector<int>> bottomMost(m, vector<int>(3, INT_MIN));
    map<char, int> colorIndex = {
        {'r', 0},
        {'g', 1},
        {'b', 2},
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int color = colorIndex[A[i][j]];
            leftMost[color] = min(leftMost[color], j);
            rightMost[color] = max(rightMost[color], j);
            topMost[j][color] = min(topMost[j][color], i);
            bottomMost[j][color] = max(bottomMost[j][color], i);
        }
    }
    int maxArea = 0;
    for (int j = 0; j < m; j++)
    {
        for (int color1 = 0; color1 < 3; color1++)
        {
            for (int color2 = color1 + 1; color2 < 3; color2++)
            {
                if (topMost[j][color1] == INT_MAX || topMost[j][color2] == INT_MAX)
                {
                    continue;
                }
                int color3 = 3 - color1 - color2;
                if (leftMost[color3] == INT_MAX)
                {
                    continue;
                }
                int vertDist = max(abs(bottomMost[j][color1] - topMost[j][color2]), abs(bottomMost[j][color2] - topMost[j][color1])) + 1;
                int horizontalDist = max(abs(j - leftMost[color3]), abs(j - rightMost[color3])) + 1;
                maxArea = max(maxArea, (vertDist * horizontalDist) / 2 + ((vertDist * horizontalDist) % 2 > 0 ? 1 : 0));
            }
        }
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    /*
    Input 1:
    A = ["rrrrr", "rrrrg", "rrrrr", "bbbbb"]
    Input 2:
    A = ["rrr", "rrr", "rrr", "rrr"]
    Input 3:
    A : [ "rrrbr", "ggrgb", "bbbrg", "rrgrr", "gbggb", "rbbgr", "rbgrg", "bbbgr", "ggbbb", "bggbr", "ggrbb", "grrrg", "rbrrg", "brrgr", "rrgbg", "bbrgr", "gbbbr", "rrbgb", "brbbr", "bgrrr", "bbggr", "rggbg", "bbggg", "gggbb", "bgbbg", "rrbgr", "rggrb", "grggr", "rggrr" ]
    */
    vector<string> A = {"rrrrr", "rrrrg", "rrrrr", "bbbbb"};
    cout << solve(A) << endl;
    vector<string> B = {"rrr", "rrr", "rrr", "rrr"};
    cout << solve(B) << endl;
    vector<string> C = {"rrrbr", "ggrgb", "bbbrg", "rrgrr", "gbggb", "rbbgr", "rbgrg", "bbbgr", "ggbbb", "bggbr", "ggrbb", "grrrg", "rbrrg", "brrgr", "rrgbg", "bbrgr", "gbbbr", "rrbgb", "brbbr", "bgrrr", "bbggr", "rggbg", "bbggg", "gggbb", "bgbbg", "rrbgr", "rggrb", "grggr", "rggrr"};
    cout << solve(C) << endl;
    // Output 1: 10
    // Output 2: 0
    return 0;
}
