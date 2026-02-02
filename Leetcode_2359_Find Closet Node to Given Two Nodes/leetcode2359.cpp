#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> graph;
    int n;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        graph.resize(n);
        for(int i = 0; i < n; i++){
            if(edges[i] == -1) continue;
            graph[i].push_back(edges[i]);
        }
        vector<int> dist1(n, -1), dist2(n, -1);
        CalculateDist(node1, dist1);
        CalculateDist(node2, dist2);
        int minVal = INT_MAX, ans = -1;
        for(int i = 0; i < n; i++){
            if(dist1[i] == -1 || dist2[i] == -1) continue;
            int val = max(dist1[i], dist2[i]);
            if(minVal > val){
                minVal = val;
                ans = i;
            }
        }
        return ans;
    }

    void CalculateDist(int start, vector<int> &dist){
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push({start, 0});
        dist[start] = 0;
        visited[start] = true;
        while(!q.empty()){
            auto [id, cost] = q.front();
            q.pop();
            for(int i = 0; i < graph[id].size(); i++){
                int end = graph[id][i];
                if(!visited[end]){
                    dist[end] = cost + 1;
                    visited[end] = true;
                    q.push({end, dist[end]});
                }
            }
        }
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