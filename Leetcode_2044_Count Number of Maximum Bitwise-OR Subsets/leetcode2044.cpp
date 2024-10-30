#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0, target = nums[0];
        for(int i = 1; i < nums.size(); i++) target |= nums[i];
        for(int i = 0; i < nums.size(); i++){
            BT(nums[i], target, i, count, nums, true);
        }
        return count;
    }

    void BT(int cur, int target, int idx, int &cnt, vector<int> nums, bool add){
        if(cur == target && add) cnt++;
        if(idx + 1 == nums.size()) return;
        BT(cur, target, idx + 1, cnt, nums, false);
        BT(cur | nums[idx + 1], target, idx + 1, cnt, nums, true);
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
        cout << sol.countMaxOrSubsets(arr) << endl;
    }
    testcase.close();
    return 0;
}