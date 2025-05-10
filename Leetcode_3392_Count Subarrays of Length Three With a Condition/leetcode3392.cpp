#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            ans += ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) ? 1 : 0;
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