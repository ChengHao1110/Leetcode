#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        if(s.length() > t.length()) return false;

        int sIdx = 0, tIdx = 0;
        while(tIdx < t.length() && sIdx < s.length()){
            if(t[tIdx] == s[sIdx]){
                sIdx++;
            }
            tIdx++;
        }

        if(sIdx == s.length()) return true;
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