#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string xs = to_string(x);
        for(int i = 0; i < xs.length() / 2; i++){
            if(xs[i] != xs[xs.length() - 1 - i]) return false;
        }
        return true;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        int num;
        ss >> num;
        if(sol.isPalindrome(num)) cout << "True" << endl;
        else cout << "False" << endl;

    }
    testcase.close();
    return 0;
}