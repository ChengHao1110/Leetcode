#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) prefix[i] = prefix[i - 1] + nums[i];
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) ans += (prefix[i] >= prefix[nums.size() - 1] - prefix[i]) ? 1 : 0;
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