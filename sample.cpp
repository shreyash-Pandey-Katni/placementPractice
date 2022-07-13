#include <bits/stdc++.h>
#include <string>
using namespace std;
void overlap(vector<pair<int, int>> v)
{
    int ans = 0;
    int count = 0;
    int maxTime = 0;
    vector<pair<int, char>> data;
    for (int i = 0; i < v.size(); i++)
    {
        data.push_back({v[i].first, 'x'});
        data.push_back({v[i].second, 'y'});
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
        ans = max(ans, count);
    }
    cout << ans << endl;
}

int getSeconds(char *time)
{
    int hour = time[0] - '0';
    int min = time[1] - '0';
    int sec = time[3] - '0';
    return hour * 3600 + min * 60 + sec;
}

int main()
{
    int t = 0;
    int n = 0;
    cin >> t;
    vector<vector<pair<int, int>>> mat;
    while (t--)
    {
        vector<pair<int, int>> temp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            // string s = "";
            // cin >> s;
            string start;
            string end;
            cin>>start>>end;
            // // int endInd = s.find(" ");
            // start = s.substr(0, endInd);
            // end = s.substr(endInd, 8);
            int timeStart = 0;
            int timeEnd = 0;
            timeStart += atoi(start.substr(0, 2).data()) * 3600;
            timeStart += atoi(start.substr(2, 2).data()) * 60;
            timeStart += atoi(start.substr(4, 2).data());
            timeEnd += atoi(end.substr(0, 2).data()) * 3600;
            timeEnd += atoi(end.substr(2, 2).data()) * 60;
            timeEnd += atoi(end.substr(4, 2).data());
            pair<int, int> PAIR1;
            PAIR1.first = timeStart;
            PAIR1.second = timeEnd;
            temp.push_back(PAIR1);
        }
        overlap(temp);
        temp.clear();
    }
    return 0;
}