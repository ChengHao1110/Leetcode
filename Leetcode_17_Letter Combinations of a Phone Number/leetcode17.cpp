#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

unordered_map<char, vector<char>> map={
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length = digits.length();
        vector<string> ans;
        CreatePhoneNumber(0, length, digits, "", ans);
        return ans;
    }

    void CreatePhoneNumber(int curDepth, int maxDepth, string digits, string phone, vector<string> &ans){
        if(curDepth == maxDepth && maxDepth != 0){
            //cout << "Find One: " << phone << endl;
            ans.push_back(phone);
            return;
        }
        for(int i = 0; i < map[digits[curDepth]].size(); i++){
            string lastPhone = phone;
            phone += map[digits[curDepth]][i];
            //cout << "phone: " << phone << endl;
            CreatePhoneNumber(curDepth + 1, maxDepth, digits, phone, ans);
            phone = lastPhone;
        }
        return;
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
        vector<string> ans;
        ans = sol.letterCombinations(input);
        for(string s : ans) cout << s << " "; cout << endl;
    }
    testcase.close();
    return 0;
}