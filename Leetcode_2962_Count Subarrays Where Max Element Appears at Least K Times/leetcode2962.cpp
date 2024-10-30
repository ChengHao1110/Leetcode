#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = INT_MIN, numCount = 0, l = 0, r = 0;
        long long int count = 0;
        for(int n : nums) if(n > maxNum) maxNum = n;
        while(r < nums.size()){
            if(nums[r] == maxNum) numCount++;
            if(numCount == k){
                count += nums.size() - r; // 1 [self] + (nums.size() - 1) - r [back elements which can be new substring]
                while(nums[l] != nums[r]){
                    count += nums.size() - r;
                    l++;
                }
                numCount--;
                l++;
            }
            r++;
        }
        return count;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    vector<int> nums;
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        int target = nums.back();
        nums.pop_back(); 
        Solution sol;
        cout << "count: " << sol.countSubarrays(nums, target) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}