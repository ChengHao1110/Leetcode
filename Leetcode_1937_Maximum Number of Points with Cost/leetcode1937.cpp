#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size(), col = points[0].size();
        vector<long long> dp;
        for(int i = 0; i < col; i++) dp.push_back(points[0][i]);

        for(int r = 1; r < row; r++){
            vector<long long> leftmax(col, 0), rightmax(col, 0);

            //leftmax
            leftmax[0] = dp[0];
            for(int i = 1; i < col; i++){
                leftmax[i] = max(leftmax[i-1], dp[i] + i);
            }
            //rightmax
            rightmax[col-1] = dp[col-1] - (col-1);
            for(int i = col-2; i >= 0; i--){
                rightmax[i] = max(rightmax[i+1], dp[i] - i);
            }

            vector<long long> newDp(col, 0);
            for(int i = 0; i < col; i++){
                newDp[i] = max(leftmax[i] - i, rightmax[i] + i) + points[r][i];
            }
            dp = newDp;
        }
        long long ans = dp[0];
        for(int i = 1; i < col; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    long long maxPoints_old(vector<vector<int>>& points) {
        //TLE
        int row = points.size(), col = points[0].size();
        vector<vector<long long>> dp;
        vector<long long> first;
        for(int i = 0; i < col; i++){
            first.push_back(points[0][i]);
        }
        dp.push_back(first);
        for(int i = 1; i < row; i++){
            vector<long long> row(col, INT_MIN);
            dp.push_back(row);
        }
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                long long dpMax = INT_MIN;
                for(int k = 0; k < col; k++){
                    dpMax = max(dpMax , dp[i-1][k] + points[i][j] - abs(j - k));
                }
                dp[i][j] = dpMax;
            }
        }
        long long ans = dp[row-1][0];
        for(int i = 1; i < col; i++){
            ans = max(ans, dp[row-1][i]);
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
        stringstream ss(input);
        int times;
        ss >> times;
        ss.clear();
        ss.str("");
        vector<vector<int>> mat;
        int num;
        while(times--){
            getline(testcase, input);
            ss << input;
            vector<int> arr;
            while(ss >> num) arr.push_back(num);
            mat.push_back(arr);
            ss.clear();
            ss.str("");
        }
        cout << sol.maxPoints(mat) << endl;
    }
    testcase.close();
    return 0;
}