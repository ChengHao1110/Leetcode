#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -1 * nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j != k){
                if((nums[j] + nums[k]) == target){
                    //put ans
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    ans.push_back(triplet);
                    j++;
                    while(nums[j] == nums[j - 1] && j < k) j++;
                }
                else if((nums[j] + nums[k]) > target){
                    k--;
                }
                else if((nums[j] + nums[k]) < target){
                    j++;
                }
            }
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
        vector<int> nums;
        int num;
        stringstream ss(input);
        while(ss >> num) nums.push_back(num);
        vector<vector<int>> ans = sol.threeSum(nums);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    testcase.close();
    return 0;
}