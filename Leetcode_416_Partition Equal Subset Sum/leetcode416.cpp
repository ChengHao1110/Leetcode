#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
        if(sum % 2 == 1) return false;
        sort(nums.begin(), nums.end());
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                if(dp[j]) continue;
                if(dp[j - nums[i]]) dp[j] = true;
                if(dp[target]) return true;
            }
        }

        return false;
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