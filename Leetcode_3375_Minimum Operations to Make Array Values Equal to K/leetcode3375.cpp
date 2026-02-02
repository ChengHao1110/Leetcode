#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minVal = INT_MAX;
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
           s.insert(nums[i]);
           minVal = min(minVal, nums[i]);
        }
        if(minVal < k) return -1;
        else if(minVal > k) return s.size();
        else return s.size() - 1;
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