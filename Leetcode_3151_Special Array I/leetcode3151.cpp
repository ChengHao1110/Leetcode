#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int i = 1; i < nums.size(); i++){
            if((nums[i] + nums[i - 1]) % 2 == 0) return false;
        }
        return true;
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
        if(sol.isArraySpecial(arr)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    testcase.close();
    return 0;
}