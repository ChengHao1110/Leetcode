#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i <= nums.size(); i++){
            vector<int> pos;
            BT(0, i, 0, nums, pos, ans);
        }
        return ans;
    }

    void BT(int curDepth, int maxDepth, int startIdx, vector<int> nums, vector<int> &pos, vector<vector<int>> &ans){
        if(curDepth == maxDepth){
            ans.push_back(pos);
            return;
        }
        for(int i = startIdx; i < nums.size(); i++){
            pos.push_back(nums[i]);
            BT(curDepth + 1, maxDepth, i + 1, nums, pos, ans);
            pos.pop_back();
        }
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
        vector<vector<int>> ans = sol.subsets(arr);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}