#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string lo = num1, sh = num2;
        if(num1.length() < num2.length()){
            lo = num2;
            sh = num1;
        }
        lo = "0" + lo;
        int loIdx = lo.length() - 1, shIdx = sh.length() - 1, carry = 0;

        for(shIdx; shIdx >= 0; shIdx--, loIdx--){
            int digit = (lo[loIdx] - '0') + (sh[shIdx] - '0') + carry;
            carry = digit / 10;
            digit %= 10;
            lo[loIdx] = digit + '0';
        }

        for(loIdx; loIdx >= 0; loIdx--){
            if(carry == 1){
                int digit = (lo[loIdx] - '0') + carry;
                carry = digit / 10;
                digit %= 10;
                lo[loIdx] = digit + '0';
            }
            else{
                break;
            }
        }

        if(lo[0] == '0') lo = lo.substr(1, lo.length() - 1);

        return lo;
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