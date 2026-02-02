#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long m = 1000000007;
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        long long ans = 0;
        if(n % 2 == 1){
            ans = (FastExponential(20, n / 2) * 5) % m;
        }
        else{
            ans = FastExponential(20, n / 2);
        }
        return ans;
    }

    long long FastExponential(long long base, long long pow){
        long long res = 1;
        while(pow > 0){
            if(pow & 1){
                res = res * base % m;
            }
            base = base * base % m;
            pow >>= 1;
        }
        return res;
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