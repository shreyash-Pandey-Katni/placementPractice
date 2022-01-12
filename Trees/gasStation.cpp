#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int numberOfStations = gas.size();
    int minIndex = -1;
    int minCost = INT16_MAX;
    int sum = 0;
    int currentGasLevel = -1;
    for (int i = 0; i < numberOfStations; i++)
    {
        sum = 0;
        currentGasLevel = 0;
        for (int j = 0; j < numberOfStations; j++)
        {
            currentGasLevel += gas[(i + j)%numberOfStations] - cost[(i + j)%numberOfStations];
            if (currentGasLevel <0)
            {
                break;
            }
        }
        if (currentGasLevel>=0)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int numberOfStations;
    cin >> numberOfStations;
    vector<int> gas(numberOfStations);
    vector<int> cost(numberOfStations);
    for (int i = 0; i < numberOfStations; i++)
    {
        cin >> gas[i];
    }
    int numberOfCosts;
    cin >> numberOfCosts;
    for (int i = 0; i < numberOfCosts; i++)
    {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
