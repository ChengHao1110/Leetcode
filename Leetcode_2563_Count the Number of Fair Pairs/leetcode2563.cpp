#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l < r){
            if(nums[l] + nums[r] > upper){
                r--;
            }
            else{
                if(nums[l] + nums[r] >= lower){
                    int curL = l + 1;
                    while(curL < r && nums[l] + nums[curL] < lower){
                        curL++;
                    }
                    ans += r - curL + 1;
                }
                l++;
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

    }
    testcase.close();
    return 0;
}