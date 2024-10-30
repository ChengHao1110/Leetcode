#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = std::count(nums.begin(), nums.end(), 1); //<algorithm>
        int tempCnt = std::count(nums.begin(), nums.begin() + count, 0), l = 0, r = count - 1;
        int minSwap = tempCnt;
        while(l < nums.size()){
            //remove l pos, add r pos
            if(nums[l] == 0) tempCnt--;
            r++;
            if(r == nums.size()) r = 0;
            if(nums[r] == 0) tempCnt++;
            if(tempCnt < minSwap) minSwap = tempCnt;
            l++;
        }
        return minSwap;
    }
    /*
    int minSwaps(vector<int>& nums) {
        int count = std::count(nums.begin(), nums.end(), 1); //<algorithm>
        int minSwap = INT_MAX, zeroCount = 0, i = 0;
        for(i; i <= nums.size() - count; i++){
            zeroCount = std::count(nums.begin() + i, nums.begin() + i + count, 0);
            //cout << zeroCount << endl;
            if(zeroCount < minSwap) minSwap = zeroCount;
        }
        int remain = 1;
        for(i; i < nums.size(); i++, remain++){
            zeroCount = std::count(nums.begin() + i, nums.end(), 0) + std::count(nums.begin(), nums.begin() + remain, 0);
            //cout << zeroCount << endl;
            if(zeroCount < minSwap) minSwap = zeroCount;
        }
        return minSwap;
    }
    */ // time limit
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> nums;
        int num;
        while(ss >> num) nums.push_back(num);
        cout << "ans: " << sol.minSwaps(nums) << endl;
    }
    testcase.close();
    return 0;
}