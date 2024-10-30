#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // leetcode
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int *sumMax_dp = new int[length];
        sumMax_dp[0] = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int curValue = nums[i];
            int curSumValue = nums[i] + sumMax_dp[i-1];
            sumMax_dp[i] = max(curSumValue, curValue);
            maxSum = max(maxSum, sumMax_dp[i]);
        }

        return maxSum;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    vector<int> nums;
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }

        Solution sol;
        int ans = sol.maxSubArray(nums);
        cout << "ans: " << ans << endl;
        nums.clear();
    }
    return 0;
}