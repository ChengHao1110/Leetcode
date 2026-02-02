#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums[0];
        vector<bool> ans;
        ans[0] = (n % 5 == 0) ? true : false;
        for(int i = 1; i < nums.size(); i++){
            n = (n * 2 + nums[i]) % 5;
            ans[i] = (n == 0) ? true : false;
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