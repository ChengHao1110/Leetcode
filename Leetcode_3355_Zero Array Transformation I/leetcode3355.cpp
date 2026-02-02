#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArr(nums.size() + 1, 0), prefixArr(nums.size(), 0);
        for(int i = 0; i < queries.size(); i++){
            diffArr[queries[i][0]]++;
            diffArr[queries[i][1] + 1]--;
        }
        prefixArr[0] = diffArr[0];
        if(prefixArr[0] < nums[0]) return false;
        for(int i = 1; i < nums.size(); i++){
            prefixArr[i] = prefixArr[i - 1] + diffArr[i];
            if(prefixArr[i] < nums[i]) return false;
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

    }
    testcase.close();
    return 0;
}