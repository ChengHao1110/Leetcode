#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if(n == 3) return values[0] * values[1] * values[2];
        vector<vector<int>> dp(n - 1, vector<int>(n, 0)); //dp[i][j], i: start vertex, j: end vertex, the min value between i and j vertex

        for(int d = 2; d <= n - 1; d++){ // the distance between i and j, d = 2 is triangle, d = 3 is quadrilateral...
            for(int i = 0; i < n - d; i++){
                int j = i + d, minVal = INT_MAX, val = values[i] * values[j];
                for(int k = i + 1; k < j; k++){ // k: the vertex between i and j
                    minVal = min(minVal, val * values[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = minVal;
            }
        }

        return dp[0][n - 1];
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