#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long base = 1, ans = 0;
        int i = columnTitle.length() - 1;
        while(i > -1){
            ans += (columnTitle[i] - 'A' + 1) * base;
            base *= 26;
            i--;
        }
        return (int)ans;
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