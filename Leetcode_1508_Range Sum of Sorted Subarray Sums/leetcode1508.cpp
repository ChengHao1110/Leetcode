#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> total;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                total.push_back(sum);
            }
        }
        sort(total.begin(), total.end());
        long long int ans = 0;
        for(int i = left - 1; i < right; i++) ans += total[i];
        return ans % 1000000007;
    }
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
        vector<int> nums;
        stringstream ss(input);
        int num, n, left, right;
        while(ss >> num) nums.push_back(num);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        ss >> n >> left >> right;
        cout << "ans: " << sol.rangeSum(nums, n, left, right) << endl;
    }
    testcase.close();
    return 0;
}