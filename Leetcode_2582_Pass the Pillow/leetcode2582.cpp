#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int move = 1, start = 1;
        while(time--){
            start += move;
            if(start == 1 || start == n) move *= -1;
        }
        return start;
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
        int n, times;
        ss >> n >> times;
        cout << sol.passThePillow(n, times) << endl;
    }
    testcase.close();
    return 0;
}