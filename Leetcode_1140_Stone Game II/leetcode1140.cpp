#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(piles.size(), 0);
        suffixSum[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n){
                    dp[i][m] = suffixSum[i];
                } 
                else{
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
                cout << "print dp table" << endl;
                for(int r = 0; r < n; r++){
                    for(int c = 0; c < n+1; c++){
                        cout << dp[r][c] << " "; 
                    }
                    cout << endl;
                }
            }
        }
        
        return dp[0][1];
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
        vector<int> arr;
        int num;
        stringstream ss(input);
        while(ss >> num) arr.push_back(num);
        cout << sol.stoneGameII(arr) << endl;
    }
    testcase.close();
    return 0;
}