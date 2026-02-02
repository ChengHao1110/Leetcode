#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long m = 1000000007;
    int numberOfWays(int n, int x) {
        vector<long long> powerList;
        for(int i = 1; i <= n; i++){
            long long num = 1;
            for(int j = 0; j < x; j++) num *= i;
            if(num > n) break;
            powerList.push_back(num);
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for(long long p : powerList){
            for(int i = n; i >= p; i--){
                dp[i] = (dp[i] + dp[i - p]) % m;
            }
        }

        return (int) dp[n];
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