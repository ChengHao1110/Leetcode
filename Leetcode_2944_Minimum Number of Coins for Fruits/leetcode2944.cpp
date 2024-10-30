#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int j = min(n,2*(i+1));
            dp[i] = prices[i] + *min_element(dp.begin()+i+1,dp.begin()+j+1);
        }
        for(int n : dp) cout << n << " "; cout << endl;
        return dp[0];
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
        stringstream ss(input);
        vector<int> nums;
        int num;
        while(ss >> num) nums.push_back(num);
        cout << "price: " << sol.minimumCoins(nums) << endl;
    }
    testcase.close();
    return 0;
}