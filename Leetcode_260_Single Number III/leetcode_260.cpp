#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        unsigned long xorSum = 0;
        for(int n: nums) xorSum ^= n;
        //cout << "xor: " << xorSum << endl;
        unsigned long diff = xorSum & -xorSum;
        //cout << "diff: " << diff << endl;
        int n1 = 0, n2 = 0;
        for(int n : nums){
            if(n & diff) n1 ^= n;
            else n2 ^= n;
        }
        vector<int> ans = {n1, n2};
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
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        vector<int> ans = sol.singleNumber(arr);
        cout << ans[0] << " " << ans[1] << endl;
    }
    testcase.close();
    return 0;
}