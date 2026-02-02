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
    vector<int> dp1, dp2, ans;
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = -1, m = -1;
        for(auto e : edges1) n = max(n, max(e[0], e[1]));
        for(auto e : edges2) m = max(m, max(e[0], e[1]));
        n++;
        m++;
        dp1.resize(n, 0);
        dp2.resize(m, 0);
        ans.resize(n, 0);
        vector<vector<int>> graph1(n), graph2(m);
        //graph 1
        for(int i = 0; i < edges1.size(); i++){
            int s = edges1[i][0], e = edges1[i][1];
            graph1[s].push_back(e);
            graph1[e].push_back(s);
        }
        //create dp 1
        for(int i = 0; i < n; i++){
            vector<bool> visited(n, false);
            queue<pair<int, int>> q;
            int cnt = 0;
            q.push({i, 0});
            visited[i] = true;
            while(!q.empty()){
                auto [idx, dist] = q.front();
                q.pop();
                if(dist <= k) cnt++;
                else continue;
                for(int j = 0; j < graph1[idx].size(); j++){
                    int e = graph1[idx][j];
                    if(!visited[e]){
                        visited[e] = true;
                        q.push({e, dist + 1});
                    }
                }
            }
            dp1[i] = cnt;
        }
        //graph 2
        for(int i = 0; i < edges2.size(); i++){
            int s = edges2[i][0], e = edges2[i][1];
            graph2[s].push_back(e);
            graph2[e].push_back(s);
        }
        //create dp 2
        for(int i = 0; i < m; i++){
            vector<bool> visited(m, false);
            queue<pair<int, int>> q;
            int cnt = 0;
            q.push({i, 0});
            visited[i] = true;
            while(!q.empty()){
                auto [idx, dist] = q.front();
                q.pop();
                if(dist <= k - 1) cnt++;
                else continue;
                for(int j = 0; j < graph2[idx].size(); j++){
                    int e = graph2[idx][j];
                    if(!visited[e]){
                        visited[e] = true;
                        q.push({e, dist + 1});
                    }
                }
            }
            dp2[i] = cnt;
        }
        int maxDp2 = *max_element(dp2.begin(), dp2.end());
        //calculate ans
        for(int i = 0; i < n; i++){
            ans[i] = dp1[i] + maxDp2;
        }
        return ans;
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