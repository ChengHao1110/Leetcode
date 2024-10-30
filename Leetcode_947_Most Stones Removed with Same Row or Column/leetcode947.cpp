#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size(), false);
        int ans = 0;
        for(int i = 0; i < stones.size(); i++){
            if(!visited[i]){
                int count = 0;
                DFS(i, count, stones, visited);
                ans += (count - 1);    
            }
        }
        return ans;
    }

    void DFS(int idx, int &count, vector<vector<int>>& stones, vector<bool> &vis){
        count++;
        vis[idx] = true;
        for(int i = 0; i < stones.size(); i++){
            if(vis[i]) continue;
            if(stones[i][0] == stones[idx][0]){
                DFS(i, count, stones, vis);
            }
            if(stones[i][1] == stones[idx][1]){
                DFS(i, count, stones, vis);
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
        stringstream ss(input);
        int num;
        ss >> num;
        ss.clear();
        ss.str("");
        vector<vector<int>> stones;
        for(int i = 0; i < num; i++){
            getline(testcase, input);
            ss << input;
            int x, y;
            ss >> x >> y;
            vector<int> cord = {x, y};
            stones.push_back(cord);
            ss.clear();
            ss.str("");
        }
        cout << sol.removeStones(stones) << endl;
    }
    testcase.close();
    return 0;
}