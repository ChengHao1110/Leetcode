#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        for(int i = 0; i < nums.size(); i++){
            arr[i] = nums[nums[i]];
        }
        return arr;
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