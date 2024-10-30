#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int num = 0;
        while(n > 1){
            bool isPrime = true;
            for(int i = 2; i <= (int)sqrt(n); i++){
                if(n % i == 0){
                    n /= i;
                    num += i;
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                num += n;
                return num;
            }
        }
        return num;
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
        cout << sol.minSteps(num) << endl;
    }
    testcase.close();
    return 0;
}