#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closetSum = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            int twoSumTarget = target - nums[i];
            int j = i + 1, k = nums.size() - 1;
            while(j != k){
                int tmpDiff = nums[j] + nums[k] - twoSumTarget;
                if(abs(tmpDiff) < diff){
                    diff = abs(tmpDiff);
                    closetSum = nums[i] + nums[j] + nums[k];
                }
                if(tmpDiff > 0){
                    k--;
                }
                else if(tmpDiff < 0){
                    j++;
                }
                else{
                    j++;
                }
            }
        }
        return closetSum;
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
        int num;
        vector<int> nums;
        stringstream ss(input);
        while(ss >> num) nums.push_back(num);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        ss >> num;
        cout << "ans: " << sol.threeSumClosest(nums, num) << endl;
    }
    testcase.close();
    return 0;
}