#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        vector<int> digits(32, 0);
        int i = 0;
        while(n > 0){
            digits[i] = n % 2;
            n /= 2;
            i++;
        }

        long long base = 1, ans = 0;
        for(int i = 31; i >= 0; i--, base *= 2){
            ans += digits[i] * base;
        }

        return (int) ans;
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