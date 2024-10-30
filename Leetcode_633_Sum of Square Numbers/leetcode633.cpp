#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        double start = sqrt(c);
        double b;
        double frac = modf(start, &b);
        for(int i = (int)start; i > 0; i--){
            int remain = c - i * i;
            frac = modf(sqrt(remain), &b);
            if(frac == 0) return true;
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
        int num;
        ss >> num;
        if(sol.judgeSquareSum(num)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    testcase.close();
    return 0;
}