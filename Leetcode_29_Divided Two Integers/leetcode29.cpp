#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int n = static_cast<long long int>(dividend);
        long long int d = static_cast<long long int>(divisor);
        bool neg = false;
        if(n < 0 && d < 0){
            n = ~n + 1;
            d = ~d + 1;
        }
        else if(n < 0 && d > 0){
            n = ~n + 1;
            neg = true;
        }
        else if(n > 0 && d < 0){
            d = ~d + 1;
            neg = true;
        }
        // divide
        long long int ans = 0;
        while(n >= d){
            long long int quotient = 1;
            long long int tmp = d;
            while(n >= tmp){
                tmp = tmp << 1;
                quotient = quotient << 1;
            }
            tmp = tmp >> 1;
            quotient = quotient >> 1;
            ans += quotient;
            n -= tmp;
        }

        if(neg) ans = ~ans + 1;
        if(ans == 0) return 0;
        else if(ans > INT_MAX) return INT_MAX;
        else if(ans < INT_MIN) return INT_MIN;
        else return ans;
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
        int n, d;
        ss >> n >> d;
        cout << sol.divide(n, d) << endl;;
    }
    testcase.close();
    return 0;
}