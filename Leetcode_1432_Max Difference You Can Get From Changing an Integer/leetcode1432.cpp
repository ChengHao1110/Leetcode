#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num), maxS = s, minS = s;
        if(s.length() == 1) return 8;

        char r = ' ';
        int idx = 0;
        //max
        while(idx < s.length()){
            if(s[idx] < '9'){
                r = s[idx];
                break;
            }
            idx++;
        }
        while(idx < s.length()){
            maxS[idx] = (s[idx] == r) ? '9' : maxS[idx];
            idx++;
        }

        //min
        if(s[0] > '1'){
            r = s[0];
            idx = 0;
            while(idx < s.length()){
                minS[idx] = (s[idx] == r) ? '1' : minS[idx];
                idx++;
            }
        }
        else{
            idx = 1;
            while(idx < s.length()){
                if(s[idx] > '1'){
                    r = s[idx];
                    break;
                }
                idx++;
            }
            while(idx < s.length()){
                minS[idx] = (s[idx] == r) ? '0' : minS[idx];
                idx++;
            }
        }

        return stoi(maxS) - stoi(minS);
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