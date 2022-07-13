/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *a[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, g;
        cin >>g >> n;
        vector<int> price;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            price.push_back(temp);
        }
        int ans = 0;
        sort(price.begin(), price.end());
        for (int i = 0; i < g; i++)
        {
            ans += price[i];
        }
        cout << ans << endl;
    }
    return 0;
}
