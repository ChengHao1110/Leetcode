#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, sum = 0;
        travel(nums, 0, ans , sum);
        return ans;
    }

    void travel(vector<int>& nums, int idx, int &ans, int sum){
        if(idx == nums.size()) return;
        sum ^= nums[idx];
        ans += sum;
        travel(nums, idx + 1, ans, sum);
        sum ^= nums[idx];
        travel(nums, idx + 1, ans, sum);
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
        vector<int> arr;
        int n;
        while(ss >> n) arr.push_back(n);
        cout << sol.subsetXORSum(arr) << endl;
    }
    testcase.close();
    return 0;
}