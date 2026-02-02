#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int n1 = 0, n2 = 0, base = 1, digit, mid, oriN = n;
        bool noCarry = false;
        while(n > 0){
            digit = n % 10;
            if(digit < 2){
                if(base * 10 > oriN){
                    noCarry = true;
                    break;
                }
                else{
                    digit += 10;
                    n -= 10;
                }
            }
            mid = digit / 2;
            n1 += mid * base;
            n2 += (digit - mid) * base;
            
            n /= 10;
            base *= 10;
        }

        if(noCarry){
            n1 += base;
        }

        return {n1, n2};
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