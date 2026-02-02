#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0, idx = 1;
        while(idx < nums.size() && nums[idx] == nums[0]) idx++;
        if(idx == nums.size()) return 0;
        for(idx; idx < nums.size();){
            int l = idx - 1, r = idx + 1;
            while(l >= 0 && nums[l] == nums[idx]) l--;
            while(r < nums.size() && nums[r] == nums[idx]) r++;
            if(r == nums.size()) break;
            if(nums[l] > nums[idx] && nums[r] > nums[idx]) ans++;
            else if(nums[l] < nums[idx] && nums[r] < nums[idx]) ans++;

            idx = r;
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