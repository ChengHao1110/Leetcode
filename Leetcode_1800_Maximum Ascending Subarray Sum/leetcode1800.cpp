#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur = nums[0], maxValue = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                cur += nums[i];
                if(maxValue < cur) maxValue = cur;
            }
            else{
                cur = nums[i];
            }
        }
        return maxValue;
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
        cout << sol.maxAscendingSum(arr) << endl;
    }
    testcase.close();
    return 0;
}