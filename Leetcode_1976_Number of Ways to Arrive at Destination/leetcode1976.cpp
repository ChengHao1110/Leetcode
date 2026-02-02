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
    int m = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        int s, e, w;
        for(int i = 0; i < roads.size(); i++){
            s = roads[i][0]; 
            e = roads[i][1]; 
            w = roads[i][2];
            graph[s].push_back({e, w});
            graph[e].push_back({s, w});
        }

        vector<long long> dp(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dp[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int cost = pq.top().first;
            s = pq.top().second;
            pq.pop();
            if (cost > dp[s]) continue;
            for(int i = 0; i < graph[s].size(); i++){
                e = graph[s][i].first; 
                w = graph[s][i].second;
                if(dp[e] > dp[s] + w){
                    dp[e] = dp[s] + w;
                    ways[e] = ways[s];
                    pq.push({dp[e], e});
                }
                else if(dp[e] == dp[s] + w){
                    ways[e] = (ways[e] + ways[s]) % m;
                }
            }
        }
        return ways[n - 1];
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

    }
    testcase.close();
    return 0;
}