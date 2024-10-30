#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0) return 0.0;
        if(x == 1.0) return 1.0;
        if(x == -1.0){
            if(abs(n) % 2 == 0) return 1.0;
            else return -1.0;
        }
        if(n == 0) return 1.0;
        long long int newN = n;
        if(n < 0){
            x = 1.0 / x;
            newN = (long long int)n * -1;
        }
        double ans = f(x, newN);
        return ans;
    }

    double f(double x, long long int n){
        if(n == 1) return x;
        if(n % 2 == 0){ 
            double num = f(x, n/2);
            //cout << "n: " << n << " num: " << num << endl;
            return num * num;
        }
        else{
            double num = x * f(x, n-1);
            //cout << "n: " << n << " num: " << num << endl;
            return num;
        }
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
        double x;
        int n;
        ss >> x >> n;
        cout << sol.myPow(x, n) << endl;
    }
    testcase.close();
    return 0;
}