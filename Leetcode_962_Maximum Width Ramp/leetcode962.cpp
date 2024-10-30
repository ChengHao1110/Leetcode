#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monoSt;
        for(int i = 0; i < nums.size(); i++){
            if(monoSt.empty() || nums[monoSt.top()] > nums[i]) monoSt.push(i);
        }
        int maxLen = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!monoSt.empty() && nums[monoSt.top()] <= nums[i]){
                maxLen = max(maxLen, i - monoSt.top());
                monoSt.pop();
            }
        }
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