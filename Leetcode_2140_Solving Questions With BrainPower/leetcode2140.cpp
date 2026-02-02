#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    /*
    vector<long long> dp;
    vector<vector<int>> q;
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        q = questions;
        dp.resize(n, 0);
        dp[0] = GetPoint(0);
        return dp[0];
    }

    long long GetPoint(int idx){
        if(idx >= q.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = max(q[idx][0] + GetPoint(idx + q[idx][1] + 1), GetPoint(idx + 1));
        return dp[idx];
    }
    */
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), 0);
        dp[questions.size() - 1] = questions[questions.size() - 1][0];
        for(int i = questions.size() - 2; i >= 0; i--){
            int nextQ = i + questions[i][1] + 1;
            if(nextQ >= questions.size()){ //last
                dp[i] = questions[i][0];
            }
            else{
                dp[i] = questions[i][0] + dp[nextQ];
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
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