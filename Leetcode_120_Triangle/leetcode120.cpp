#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int maxLevel = triangle.size();
        vector<int> dp(triangle[maxLevel - 1].size());
        for(int i = 0; i < triangle[maxLevel - 1].size(); i++) dp[i] = triangle[maxLevel - 1][i];
        
        for(int i = maxLevel - 2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
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