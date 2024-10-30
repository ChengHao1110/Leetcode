#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class CMP{
    public:
    bool operator() (pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> cost(n, vector<int>(2, INT_MAX));
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for(int i = 0 ; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }
        
        // 1st dijkstra
        cost[source][0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> pq;
        pq.push({cost[source][0], source});
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            int c = cur.first, id = cur.second;
            if (c > cost[id][0]) continue;
            for(int i = 0; i < adj[id].size(); i++){
                int weight = edges[adj[id][i].second][2], movetoId = adj[id][i].first;
                int newCost = (weight == -1) ? c + 1 : c + weight;
                if(newCost < cost[movetoId][0]){
                    cost[movetoId][0] = newCost;
                    pq.push({cost[movetoId][0], movetoId});
                } 
            }
        }
        cout << "1st cost = " << cost[destination][0] << endl;
        if(cost[destination][0] > target) return vector<vector<int>>();

        // 2nd dijkstra
        int diff = target - cost[destination][0];
        cost[source][1] = 0;
        while(!pq.empty()) pq.pop();
        pq.push({cost[source][0], source});
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            int c = cur.first, id = cur.second;
            if (c > cost[id][1]) continue;
            for(int i = 0; i < adj[id].size(); i++){
                int weight = edges[adj[id][i].second][2], movetoId = adj[id][i].first;
                if (weight == -1) weight = 1;

                if(edges[adj[id][i].second][2] == -1){
                    int newWeight = diff + cost[movetoId][0] - c;
                    if(newWeight > weight){
                        edges[adj[id][i].second][2] = newWeight;
                        weight = newWeight;
                    }
                }

                int newCost = c + weight;
                if(newCost < cost[movetoId][1]){
                    cost[movetoId][1] = newCost;
                    pq.push({cost[movetoId][1], movetoId});
                } 
            }
        }
        cout << "2nd cost = " << cost[destination][1] << endl;
        if(cost[destination][1] != target) return vector<vector<int>>();

        for(int i = 0; i < edges.size(); i++){
            if(edges[i][2] == -1) edges[i][2] = 1;
        } 
        return edges;
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
        stringstream ss(input);
        int n, s, d, target, e;
        ss >> n >> s >> d >> target >> e;
        vector<vector<int>> edges;
        for(int i = 0; i < e; i++){
            getline(testcase, input);
            stringstream sss(input);
            int n1, n2, w;
            sss >> n1 >> n2 >> w;
            vector<int> edge = {n1, n2, w};
            edges.push_back(edge);
        }
        vector<vector<int>> ans = sol.modifiedGraphEdges(n, edges, s, d, target);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}