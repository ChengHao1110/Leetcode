#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), maxS = s, minS = s;
        char replaced = ' ';
        int idx = 0;
        // max
        while(idx < s.length()){
            if(s[idx] < '9'){
                replaced = s[idx];
                break;
            }
            idx++;
        }
        while(idx < s.length()){
            if(s[idx] == replaced){
                maxS[idx] = '9';
            }
            idx++;
        }
        // min
        idx = 0;
        while(idx < s.length()){
            if(s[idx] > '0'){
                replaced = s[idx];
                break;
            }
            idx++;
        }
        while(idx < s.length()){
            if(s[idx] == replaced){
                minS[idx] = '0';
            }
            idx++;
        }
        int ans = stoi(maxS) - stoi(minS);
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

    }
    testcase.close();
    return 0;
}