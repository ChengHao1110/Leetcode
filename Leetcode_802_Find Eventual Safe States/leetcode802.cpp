#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, colors(n, 0);
        for(int i = 0; i < n; i++){
            if(DFS(i, colors, graph)) ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    bool DFS(int curNode, vector<int> colors, vector<vector<int>>& graph){
        const int gray = 1, black = 2;
        if(colors[curNode] == 2) return true;
        if(colors[curNode] == 1) return false;

        colors[curNode] = gray;
        
        for(int i = 0; i < graph[curNode].size(); i++){
            int end = graph[curNode][i];
            if(colors[end] == gray || !DFS(end, colors, graph)){
                return false;
            }
        }
        
        colors[curNode] = black;
        return true;
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