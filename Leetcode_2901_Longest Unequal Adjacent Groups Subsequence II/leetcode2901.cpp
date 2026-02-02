#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> dp(words.size(), 0);
        vector<int> lastWordIdx(words.size(), -1);
        int maxLengthIdx = 0, maxLength = 0;
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < i; j++){
                if(CheckHammingDistance(words[i], words[j]) && groups[i] != groups[j] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    lastWordIdx[i] = j;
                }
            }
            if(dp[i] > maxLength){
                maxLength = dp[i];
                maxLengthIdx = i;
            }
        }
        vector<string> ans;
        int curIdx = maxLengthIdx;
        while(curIdx != -1){
            ans.push_back(words[curIdx]);
            curIdx = lastWordIdx[curIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool CheckHammingDistance(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        int diff = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]) diff++;
            if(diff > 1) return false;
        }
        if(diff == 1) return true;
        else return false;
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