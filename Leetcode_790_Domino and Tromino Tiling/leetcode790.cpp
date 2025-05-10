#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        vector<long long> dp(n + 1, 0);
        long long m = 1000000007;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i < n + 1; i++){
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % m;
        }
        return dp[n];
    }
};

int main(){
    string input;
    Solution sol;
    cout << sol.numTilings(1000) << endl;
    return 0;
}