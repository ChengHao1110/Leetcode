#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

bool StrLength(string s1, string s2){
    return s1.length() < s2.length();
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end(), StrLength);
        int maxLength = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < maxLength; j++){
                if(strs[0][j] != strs[i][j]){
                    maxLength = j;
                    break;
                } 
            }
        }
        string ans = "";
        for(int i = 0; i < maxLength; i++) ans += strs[0][i];
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
        vector<string> strs;
        stringstream ss(input);
        string str;
        while(ss >> str) strs.push_back(str);
        cout << sol.longestCommonPrefix(strs) << endl;
    }
    testcase.close();
    return 0;
}