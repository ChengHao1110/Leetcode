#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxRes = nums[0], maxEnding = nums[0], minRes = nums[0], minEnding = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxEnding = max(maxEnding + nums[i], nums[i]);
            maxRes = max(maxRes, maxEnding);
        }
        for(int i = 1; i < nums.size(); i++){
            minEnding = min(minEnding + nums[i], nums[i]);
            minRes = min(minRes, minEnding);
        }
        return max(maxRes, abs(minRes));
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