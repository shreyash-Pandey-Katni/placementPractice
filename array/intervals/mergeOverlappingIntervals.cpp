#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
struct Interval
{
    int start;
    int end;
};

vector<Interval> sort(vector<Interval> &A)
{
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b)
         { return a.start < b.start; });
    return A;
}

vector<Interval> merge(vector<Interval> &A)
{
    sort(A);
    if (A.empty())
        return A;
    if (A.size() == 1)
        return A;
    vector<Interval> result = {A[0]};
    int n = A.size();
    int oldIntervalIndex = 1;
    int newIntervalIndex = 0;
    while (oldIntervalIndex < n)
    {
        if (result[newIntervalIndex].end < A[oldIntervalIndex].start)
        {
            result.push_back(A[oldIntervalIndex++]);
            newIntervalIndex++;
        }
        else
        {
            result[newIntervalIndex].end = max(result[newIntervalIndex].end, A[oldIntervalIndex++].end);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<Interval> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {17, 20}};
    vector<Interval> result = merge(intervals);
    for (auto interval : result)
    {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << endl;
    return 0;
}
