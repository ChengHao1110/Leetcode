#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
    public:
        long long countPairs(int n, vector<vector<int>>& edges) {
            if(edges.size() == 0) return (long long int)n * (long long int)(n - 1) / 2;
            vector<vector<int>> map;
            map.resize(n);
            for(int i = 0; i < edges.size(); i++){
                map[edges[i][0]].push_back(edges[i][1]);
                map[edges[i][1]].push_back(edges[i][0]);
            }
    
            vector<bool> visited(n, false);
            stack<int> st;
            vector<long long int> groupCnt;
            for(int i = 0; i < n; i++){
                if(visited[i] == true) continue;
                int cnt = 1;
                visited[i] = true;
                st.push(i);
                while(!st.empty()){
                    int cur = st.top();
                    st.pop();
                    for(auto e : map[cur]){
                        if(!visited[e]){
                            visited[e] = true;
                            st.push(e);
                            cnt++;
                        }
                    }
                }
                groupCnt.push_back(cnt);
            }
            
            long long int ans = 0;
            for(int i = 0; i < groupCnt.size(); i++){
                for(int j = i + 1; j < groupCnt.size(); j++){
                    ans += groupCnt[i] * groupCnt[j];
                }
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
        stringstream s(input);
        int n, edgeCnt;
        s >> n >> edgeCnt;
        vector<vector<int>> edges;
        for(int i = 0; i < edgeCnt; i++){
            getline(testcase, input);
            stringstream ss(input);
            int s, e;
            ss >> s >> e;
            vector<int> edge = {s, e};
            edges.push_back(edge);
        }
        cout << sol.countPairs(n, edges) << endl;
    }
    testcase.close();
    return 0;
}