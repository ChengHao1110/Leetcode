#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> table;
        for(int i = 0; i < s.length() - 1; i++){
            string subString = s.substr(i, 2);
            string revStr = subString;
            reverse(revStr.begin(), revStr.end());
            //cout << "sub: " << subString << " rev: " << revStr << endl;
            if(subString == revStr) return true;
            if(table.find(revStr) != table.end()) return true;
            else table.insert(subString);
        }
        return false;
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
        if(sol.isSubstringPresent(input)) cout << "True" << endl;
        else cout << "False" << endl;
    }
    testcase.close();
    return 0;
}