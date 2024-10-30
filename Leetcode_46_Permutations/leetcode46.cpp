#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> possible;
        Permutation(nums, possible, ans);
        return ans;
    }

    void Permutation(vector<int> &nums, vector<int> pos, vector<vector<int>> &ans){
        if(nums.size() == 1){
            pos.push_back(nums[0]);
            ans.push_back(pos);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            sort(nums.begin(), nums.end());
            pos.push_back(nums[i]);
            vector<int> copy = nums;
            vector<int>::iterator iter = find(copy.begin(), copy.end(), nums[i]);
            copy.erase(iter);
            Permutation(copy, pos, ans);
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
        vector<vector<int>> ans = sol.permute(arr);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}