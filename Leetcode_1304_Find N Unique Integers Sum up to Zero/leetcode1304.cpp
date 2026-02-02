#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        if(n % 2 != 0) arr.push_back(0);
        for(int i = 1; i <= n / 2; i++){
            arr.push_back(i);
            arr.push_back(-i);
        }
        return arr;
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