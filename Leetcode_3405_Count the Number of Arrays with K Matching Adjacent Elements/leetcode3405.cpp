#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long mod = 1000000007;
    int countGoodArrays(int n, int m, int k) {
        long long ans = (m * FastExponential(m - 1, n - k - 1)) % mod, c = Combination(n - 1, k);
        ans = (ans * c) % mod;
        return ans;
    }

    long long FastExponential(long long base, int pow){
        long long res = 1;
        while(pow){
            if(pow & 1 == 1){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            pow >>= 1;
        }
        return res;
    }

    long long modInverse(int a, int b) {
        int x0 = 1, x1 = 0;
        int r0 = a, r1 = b;
        while (r1 != 0) {
            int q = r0/r1, rr = r1, xx = x1;
            r1 = r0-q * r1;
            x1 = x0-q * x1;
            r0 = rr;
            x0 = xx;
        }
        if (x0 < 0) x0+= b;
        return x0;
    }

    long long Combination(int n, int r){
        if(n == r || r == 0) return 1;
        int  maxVal = max(r, n - r), minVal = min(r, n - r);
        long long numerator = Multiplier(maxVal + 1, n);
        long long denominator = Multiplier(1, minVal);
        denominator = modInverse(denominator, mod);
        return numerator * denominator % mod;
    }

    long long Multiplier(int s, int e){
        long long res = 1;
        while(s <= e){
            res = (res * s) % mod;
            s++;
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