#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx = 0, diffCnt = 0;
        char s1Diff = 'A', s2Diff = 'A';
        bool canSwap = false;
        while(diffCnt < 3 && idx < s1.length()){
            if(s1[idx] != s2[idx]){
                diffCnt++;
                if(s1Diff == 'A'){
                    s1Diff = s1[idx];
                    s2Diff = s2[idx];
                }
                else{
                    if(s2Diff == s1[idx] && s1Diff == s2[idx]){
                        canSwap = true;
                    }
                    else{
                        break;
                    }
                }
            }
            idx++;
        }
        if(diffCnt == 0) return true;
        if(diffCnt < 3 && canSwap) return true;
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
        stringstream ss(input);
        string s1, s2;
        ss >> s1 >> s2;
        if(sol.areAlmostEqual(s1, s2)){
            cout << "True" << endl;
        }
        else{
            cout << "False" << endl;
        }
    }
    testcase.close();
    return 0;
}