#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int sum = 1;
        for(int i = 1; i < s.length(); i++){
            sum += (s[i] == '(') ? 1 : -1;
            if(sum == 0){
                sum = 1;
                i++;
            }
            else{
                ans += s[i];
            }
        }
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