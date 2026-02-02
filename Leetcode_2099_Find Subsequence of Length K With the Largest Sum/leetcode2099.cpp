#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numPos;
        for(int i = 0; i < nums.size(); i++){
            numPos.push_back({nums[i], i});
        }
        sort(numPos.begin(), numPos.end(), greater<pair<int, int>>());
        vector<int> pos;
        for(int i = 0; i < k; i++){
            pos.push_back(numPos[i].second);
        }
        sort(pos.begin(), pos.end());
        vector<int> ans;
        for(int i = 0; i < pos.size(); i++){
            ans.push_back(nums[pos[i]]);
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