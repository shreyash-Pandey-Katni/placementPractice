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
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> ans;
    int n = intervals.size();
    int i = 0;
    
    // Add all intervals that end before the newInterval starts
    while (i < n && intervals[i].end < newInterval.start) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Merge intervals that overlap with newInterval
    while (i < n && intervals[i].start <= newInterval.end) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }
    
    ans.push_back(newInterval); // Add the merged newInterval
    
    // Add remaining intervals
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<Interval> intervals = {{1, 3}, {6, 9}};
    Interval newInterval = {2, 5};
    // vector<Interval> result = insert(intervals, newInterval);
    // for (auto interval : result)
    // {
    //     cout << "[" << interval.start << ", " << interval.end << "] ";
    // }
    // cout << endl;
    // intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    // newInterval = {4, 8};
    // result = insert(intervals, newInterval);
    // for (auto interval : result)
    // {
    //     cout << "[" << interval.start << ", " << interval.end << "] ";
    // }
    // cout << endl;
    // intervals = {{1, 5}};
    // newInterval = {2, 3};
    // result = insert(intervals, newInterval);
    // for (auto interval : result)
    // {
    //     cout << "[" << interval.start << ", " << interval.end << "] ";
    // }
    // cout << endl;
    /*
    A : [ (1, 2), (3, 6) ]
B : (10, 8)
    */
    intervals = {{1, 2}, {3, 6}};
    newInterval = {10, 8};
    vector<Interval> result = insert(intervals, newInterval);
    for (auto interval : result)
    {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    return 0;
}
