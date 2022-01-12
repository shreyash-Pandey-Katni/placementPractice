#include <iostream>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T, open_count = 0, close_count = 0, i;
    cin >> T;
    string S;
    char ch;
    int swaps;
    while (T--)
    {
        cin >> S;
        swaps = -1;
        for (i = 0; i < S.length(); i++)
        {
            ch = S.at(i);
            if (ch == '(')
                open_count += 1;
            else
                close_count += 1;
            if ((open_count == close_count) && i != S.length() - 1)
            {
                if (S.at(i + 1) == '(' && S.at(i + 2) == ')')
                    swaps = 1;
            }
        }
        // cout << swaps << endl;
        if (swaps == -1)
        {
            open_count = 0, close_count = 0;
            for (i = 0; i < S.length(); i++)
            {
                if (S.at(i) == '(')
                    open_count += 1;
                else
                    break;
                if (S.at(S.length() - i - 1) == ')')
                    close_count += 1;
                else
                    break;
            }
            if (open_count > close_count)
                swaps = close_count;
            else
                swaps = open_count;
        }
        cout << swaps << "\n"<< flush;
    }
    return 0;
}