#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        // shorten
        string newString = "";
        for(int l = 0, r = 0; l < s.length();){
            char curCh = s[l];
            while(r < s.length() && s[r] == curCh) r++;
            newString += s[l];
            l = r;
        }
        cout << newString << endl;
        vector<vector<int>> dp(newString.length(), vector<int>(newString.length(), -1));
        return f(0, newString.length()-1, newString, dp);
    }

    int f(int i, int j, string s, vector<vector<int>> &dp){     
        //cout << "compute dp[" << i << "][" << j << "]" << endl;   
        if(dp[i][j] != -1) return dp[i][j]; // computed
        if(i == j){
            dp[i][j] = 1;
            //PrintTable(dp);
            return dp[i][j];
        }
        if(s[i] == s[j]) return f(i, j-1, s, dp); // xyzx == xyz
        // s[i] != s[j]
        int ans = f(i, j-1, s, dp) + 1;
        for(int k = i + 1; k < j - 1; k++){
            if(s[k] == s[j]){
                ans = min(ans, f(i, k-1, s, dp) + f(k, j-1, s, dp));
            }
        }
        //PrintTable(dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    void PrintTable(vector<vector<int>> dp){
        cout << "print dp table" << endl;
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[i].size(); j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
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
        cout << sol.strangePrinter(input) << endl;
    }
    testcase.close();
    return 0;
}