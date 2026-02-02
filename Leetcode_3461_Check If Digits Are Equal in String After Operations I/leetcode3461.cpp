#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.length() == 2){
            if(s[0] == s[1]) return true;
            else return false;
        }

        string newS = "";
        for(int i = 0; i < s.length() - 1; i++){
            newS += to_string((s[i] - '0' + s[i + 1] - '0') % 10);
        }

        return hasSameDigits(newS);
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