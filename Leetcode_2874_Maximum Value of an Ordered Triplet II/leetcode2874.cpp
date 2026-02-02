#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> preixSum(nums.size(), 0), suffixSum(nums.size(), 0);
        preixSum[0] = nums[0];
        suffixSum[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++){
            preixSum[i] = max(preixSum[i - 1], nums[i]);
            suffixSum[nums.size() - 1 - i] = max(suffixSum[nums.size() - i], nums[nums.size() - 1 - i]);
        }
        long long ans = 0;
        for(int i = 1; i < preixSum.size()- 1; i++){
            ans = max(ans, (long long)(preixSum[i - 1] - nums[i]) * suffixSum[i + 1]);
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

    }
    testcase.close();
    return 0;
}