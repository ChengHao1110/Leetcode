#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 > num2){
                num1 -= num2;
            }
            else{
                num2 -= num1;
            }
            cnt++;
        }
        return cnt;
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