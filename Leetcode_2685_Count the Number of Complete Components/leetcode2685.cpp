#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            visited[i] = true;
            int nodeCnt = 0, edgeCnt = 0;
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int cur = st.top();
                st.pop();
                nodeCnt++;
                edgeCnt += graph[cur].size();
                for(int j = 0; j < graph[cur].size(); j++){
                    if(!visited[graph[cur][j]]){
                        visited[graph[cur][j]] = true;
                        st.push(graph[cur][j]);
                    }
                }
            }
            if(nodeCnt * (nodeCnt - 1) == edgeCnt) ans++;
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