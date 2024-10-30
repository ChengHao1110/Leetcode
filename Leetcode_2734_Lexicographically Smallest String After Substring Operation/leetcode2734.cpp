#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int offset = 0;
        while(s[offset] == 'a' && offset < s.length()) offset++;
        if(offset == s.length()){ // string only contains 'a'
            s[s.length() - 1] = 'z';
            return s;
        }
        else{
            while(s[offset] != 'a' && offset < s.length()){
                s[offset]--;
                offset++;
            }
        }
        return s;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    Solution sol;
    string data;
    while(getline(testcase, data)){
        cout << sol.smallestString(data) << endl;
    }
    return 0;
}