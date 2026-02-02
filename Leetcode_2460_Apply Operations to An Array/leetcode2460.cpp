#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == 0) continue;
            if(nums[i] == nums[i + 1]){
                ans.push_back(nums[i] * 2);
                nums[i + 1] = 0;
                i++;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        if(nums[nums.size() - 1] != 0) ans.push_back(nums[nums.size() - 1]);
        int remain = nums.size() - ans.size();
        for(int i = 0; i < remain; i++) ans.push_back(0);

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