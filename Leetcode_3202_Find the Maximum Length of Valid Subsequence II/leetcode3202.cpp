#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<int> dp(k, 0);
        int ans = 0;
        for(int possibleRemainder = 0; possibleRemainder < k; possibleRemainder++){
            for(int num : nums){
                int r = num % k;
                // (num + x) % k = possibleRemainder, x = ((possibleRemainder + k) - (num % k)) % k
                int match = (possibleRemainder + k - r) % k;

                dp[r] = dp[match] + 1;
                ans = max(ans, dp[r]);
            }
            dp.assign(k, 0);
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