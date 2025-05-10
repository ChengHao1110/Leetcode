#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
    public:
        bool doesValidArrayExist(vector<int>& derived) {
            int sum = 0;
            for(int n : derived) sum ^= n;
            if(sum == 1) return false;
            return true;
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