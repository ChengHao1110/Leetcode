#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> nextCell;
        vector<int> dp(n * n + 1, INT_MAX);
        bool smallToLarge = true;
        int idx = 1;
        for(int i = n - 1; i >= 0; i--){
            if(smallToLarge){
                for(int j = 0; j < n; j++){
                    nextCell[idx] = (board[i][j] == -1) ? idx : board[i][j];
                    idx++;
                }
            }
            else{
                for(int j = n - 1; j >= 0; j--){
                    nextCell[idx] = (board[i][j] == -1) ? idx : board[i][j];
                    idx++;
                }
            }
            smallToLarge = !smallToLarge;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dp[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()){
            auto [cost, id] = pq.top();
            pq.pop();
            for(int i = 1; i <= 6; i++){
                int nextId = id + i;
                if(nextId > n * n) continue;
                nextId = nextCell[nextId];
                if(dp[nextId] > cost + 1){
                    dp[nextId] = cost + 1;
                    pq.push({cost + 1, nextId});
                }
            }
        }

        if(dp[n * n] == INT_MAX) return -1;
        return dp[n * n];
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