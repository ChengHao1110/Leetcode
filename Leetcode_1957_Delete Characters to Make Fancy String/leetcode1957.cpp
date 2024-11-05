#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int left = 0, right = 0, times = 0;
        char cur = ' ';
        while(right < s.length()){
            if(s[right] == cur){
                times++;
            }
            else{
                cur = s[right];
                if(times > 2){
                    // erase
                    s.erase(s.begin() + left + 2, s.begin() + right);
                    right = left + 2;
                }
                left = right;
                times = 1;
            }
            right++;
        }
        if(times > 2){
            // erase
            s.erase(s.begin() + left + 2, s.begin() + right);
        }
        return s;
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
        cout << sol.makeFancyString(input) << endl;
    }
    testcase.close();
    return 0;
}