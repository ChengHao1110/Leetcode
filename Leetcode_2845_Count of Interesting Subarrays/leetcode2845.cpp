#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, int> table;
            table[0] = 1;
            long long ans = 0;
            int prefixSum = 0;
            for(int i = 0; i < nums.size(); i++){
                prefixSum += (nums[i] % modulo == k) ? 1 : 0;
                ans += table[(prefixSum + modulo - k) % modulo];
                table[prefixSum % modulo]++;
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
        stringstream ss(input);
        int m, k;
        ss >> m >> k;
        getline(testcase, input);
        stringstream sss(input);
        int num;
        vector<int> nums;
        while(sss >> num) nums.push_back(num);
        cout << sol.countInterestingSubarrays(nums, m, k) << endl;
    }
    testcase.close();
    return 0;
}