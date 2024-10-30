#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<vector<int>, int>> newTimes;
        for(int i = 0; i < times.size(); i++) newTimes.push_back({times[i], i});
        sort(newTimes.begin(), newTimes.end());
        for(int i = 0; i < times.size(); i++){
            cout << newTimes[i].first[0] << " " << newTimes[i].first[1] << ", " << newTimes[i].second << endl;
        }
        vector<bool> isEmpty(times.size(), true);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < newTimes.size(); i++){
            int idx = 0;
            if(pq.empty()){
                for(idx; idx < isEmpty.size(); idx++) if(isEmpty[idx]) break;
                isEmpty[idx] = false;
                pq.push({newTimes[i].first[1], idx});
            }
            else{
                while(!pq.empty()){
                    pair<int, int> cur = pq.top();
                    cout << "TOP:" << cur.first << endl;
                    if(cur.first > newTimes[i].first[0]){
                        for(idx; idx < isEmpty.size(); idx++) if(isEmpty[idx]) break;
                        isEmpty[idx] = false;
                        pq.push({newTimes[i].first[1], idx});
                        break;
                    }
                    else{
                        pq.pop();
                        isEmpty[cur.second] = true;
                    }
                }
                if(pq.empty()){
                    for(idx; idx < isEmpty.size(); idx++) if(isEmpty[idx]) break;
                    isEmpty[idx] = false;
                    pq.push({newTimes[i].first[1], idx});
                }
            }

            if(newTimes[i].second == targetFriend){
                return idx;
            }
        }
        
        return -1;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        vector<vector<int>> time;
        stringstream ss(input);
        int s, e;
        while(ss >> s >> e){
            time.push_back(vector<int>{s, e});
        }
        getline(testcase, input);
        cout << sol.smallestChair(time, stoi(input)) << endl;
    }
    testcase.close();
    return 0;
}