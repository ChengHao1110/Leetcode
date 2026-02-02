#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0, nOdd, nEven, mOdd, mEven;
        if(n % 2 == 0){
            nOdd = n / 2;
            nEven = n / 2;
        }
        else{
            nOdd = n / 2 + 1;
            nEven = n / 2;
        }

        if(m % 2 == 0){
            mOdd = m / 2;
            mEven = m / 2;
        }
        else{
            mOdd = m / 2 + 1;
            mEven = m / 2;
        }
        
        ans = nOdd * mEven + nEven * mOdd;
        return ans;
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