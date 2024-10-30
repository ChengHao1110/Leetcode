#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
#include<sstream>

using namespace std;

class Solution {
public:
    // leetcode
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int *productMax_dp = new int[length];
        int *productMin_dp = new int[length];
        productMax_dp[0] = nums[0];
        productMin_dp[0] = nums[0];

        int maxProduct = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curValue = nums[i];
            int curMaxValue = productMax_dp[i-1] * curValue;
            int curMinValue = productMin_dp[i-1] * curValue;
            productMax_dp[i] = max( max(curValue, curMaxValue), curMinValue);
            productMin_dp[i] = min( min(curValue, curMaxValue), curMinValue);
            if(productMax_dp[i] > maxProduct) maxProduct = productMax_dp[i];
        }
        return maxProduct;
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
        int ans = sol.maxProduct(nums);
        cout << "ans: " << ans << endl;
        nums.clear();
    }
    return 0;
}