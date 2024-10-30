#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0) return true;
        if(s.length() > 0 && p.length() == 0) return false;
        if(s.length() == 0 && p.length() > 0){
            for(int i = 0; i < p.length(); i++) if(p[i] != '*') return false;
            return true;
        }

        int sLen = s.length() + 1, pLen = p.length();
        bool **dp = new bool*[pLen];
        for(int i = 0; i < pLen; i++) dp[i] = new bool[sLen];
        //initialize (first col for empty case *)
        for(int i = 0; i < pLen; i++) for(int j = 0; j < sLen; j++) dp[i][j] = false;

        //check first
        int firstCorrectIdx = 0;
        if(p[0] == '*'){
            for(int i = 0; i < sLen; i++) dp[0][i] = true;
        }
        else if(p[0] == '?'){
            firstCorrectIdx = 1;
            dp[0][1] = true;
        }
        else{
            if(p[0] != s[0]) return false;
            else{
                firstCorrectIdx = 1;
                dp[0][1] = true;
            }
        }
        
        //update dp
        bool find = false;
        for(int i = 1; i < pLen; i++){
            find = false;
            if(p[i] == '*'){
                for(int j = firstCorrectIdx; j < sLen; j++) dp[i][j] = true;
                find = true;
            }
            else if(p[i] == '?'){
                for(int j = firstCorrectIdx + 1; j < sLen; j++){
                    if(dp[i - 1][j - 1]){
                        if(!find){
                            find = true;
                            firstCorrectIdx = j;
                        }
                        dp[i][j] = true;
                    }
                }
            }
            else{
                for(int j = firstCorrectIdx + 1; j < sLen; j++){
                    if(dp[i - 1][j - 1] && p[i] == s[j - 1]){
                        if(!find){
                            find = true;
                            firstCorrectIdx = j;
                        }
                        dp[i][j] = true;
                    }                
                }
            }
            if(!find){
                //cout << "FAIL in row: " << (i) << endl;
                PrintDPTable(dp, pLen, sLen);
                return false;
            }
        }
        PrintDPTable(dp, pLen, sLen);
        return dp[pLen - 1][sLen - 1];
    }

    void PrintDPTable(bool **dp, int rows, int cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dp[i][j]) cout << "T ";
                else cout << "F ";
            }
            cout << endl; 
        } 
        cout << endl; 
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input, s, p;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        ss >> s >> p;
        if(sol.isMatch(s, p)) cout << "Ans: True" << endl;
        else cout << "Ans: False" << endl;
    }
    return 0;
}