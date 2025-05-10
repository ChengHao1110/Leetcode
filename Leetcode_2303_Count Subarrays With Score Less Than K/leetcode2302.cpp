#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0, r = 0;
        long long pre = 0;
        vector<long long> prefixSum(nums.size() + 1, 0);
        long long ans = 0, res;
        while(r < nums.size()){
            pre += nums[r];
            prefixSum[r + 1] = pre;
            res = (pre - prefixSum[l]) * (r - l + 1);
            if(res < k){
                ans += (r - l + 1);
            }
            else{
                while(res >= k && l < r){
                    l++;
                    res = (pre - prefixSum[l]) * (r - l + 1);
                }
                if(res < k) ans += (r - l + 1);
            }
            r++;
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