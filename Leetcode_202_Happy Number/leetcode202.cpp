#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int d = 0;
        unordered_set<int> table;
        while(table.find(n) == table.end()){
            table.insert(n);
            int newNum = 0;
            while(n > 0){
                d = n % 10;
                newNum += d * d;
                n /= 10;
            }
            if(newNum == 1) return true;
            n = newNum;
        }
        return false;
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