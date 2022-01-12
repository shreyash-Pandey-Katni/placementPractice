#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> queries(vector<vector<int>> query){
    // vector<int> res;
    unordered_map<int,vector<int>> m;
    int numberOfQueries = query.size();
    int index = 0;
    for (int i = 0; i < numberOfQueries;i++){
        int type = query[i][0];
        int value = query[i][1];
        if(type == 1){
            if(m.find(value) == m.end()){
                m[value] = vector<int>();
            }
            m[value].push_back(index++);
        }
        else {
            int newValue = query[i][2];
            if(value == newValue){
                continue;
            }
            if(m.find(newValue) != m.end()){
                m[newValue].insert(m[newValue].end(),m[value].begin(),m[value].end());
                m.erase(value);
                continue;
            }
            m[newValue] = m[value];
            m.erase(value);
        } 
    }
    vector<int> res;
    for (auto it = m.begin(); it != m.end(); it++){
        // m.erase(it->first);
        for (int i = 0; i < it->second.size(); i++){
            if(it->second[i] >= res.size())
                res.push_back(it->first);
            else res.insert(res.begin()+it->second[i], it->first);
            // res[it->second[i]] = it->first;
        }
        
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int numberOfQueries;
    cin >> numberOfQueries;
    unordered_map<int,vector<int>> m;
    int index = 0;
    vector<vector<int>> query(numberOfQueries);
    for (int i = 0; i < numberOfQueries; i++){
        int type;
        cin >> type;
        int value;
        cin >> value;
        if(type == 1){
            if(m.find(value) == m.end()){
                m[value] = vector<int>();
            }
            m[value].push_back(index++);
        }
        else {
            int newValue;
            cin >> newValue;
            if(value == newValue){
                continue;
            }
            if(m.find(newValue) != m.end()){
                m[newValue].insert(m[newValue].end(),m[value].begin(),m[value].end());
                m.erase(value);
                continue;
            }
            m[newValue] = m[value];
            m.erase(value);
        }
    }
    vector<int> res(index,0);
    for (auto it = m.begin(); it != m.end(); it++){
        // m.erase(it->first);
        for (int i = 0; i < it->second.size(); i++){
            res[it->second[i]] = it->first;
        }
    }

    // vector<int> res = queries(query);
    // // cout<<res<<endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
