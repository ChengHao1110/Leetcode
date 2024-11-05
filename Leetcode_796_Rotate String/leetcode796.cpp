#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        for(int i = 0; i < s.length(); i++){
            int l = i, r = 0, match = 0;
            while(s[l] == goal[r] && match < goal.length()){
                l++;
                if(l == s.length()) l = 0;
                r++;
                match++;
            }
            if(match == goal.length()) return true;
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
        stringstream ss(input);
        string s, goal;
        ss >> s >> goal;
        if(sol.rotateString(s, goal)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    testcase.close();
    return 0;
}