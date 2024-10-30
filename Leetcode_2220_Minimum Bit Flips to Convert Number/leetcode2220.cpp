#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int sum = 0;
        while(diff > 0){
            sum += diff & 1;
            diff = diff >> 1;
        }
        return sum;
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