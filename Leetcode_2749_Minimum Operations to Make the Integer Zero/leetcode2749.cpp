#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 0; k <= 60; k++){
            long long r = num1 - (long long)num2 * k;
            if(r < k) return -1;
            if(k >= __builtin_popcountll(r)) return k;
        }
        return -1;
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