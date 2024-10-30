#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = INT_MIN, curLen = 0, maxLen = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                curLen = 1;
                maxLen = 1;
            }
            else if(nums[i] == maxNum){
                if(nums[i] == nums[i - 1]) curLen++;
                else curLen = 1;
            }
            else{
                maxLen = max(maxLen, curLen);
            }
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
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