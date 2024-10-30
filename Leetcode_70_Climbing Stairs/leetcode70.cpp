#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n, 0);
        if(n == 1) return 1;
        if(n == 2) return 2;
        ans[0] = 1;
        ans[1] = 2;
        for(int i = 2; i < n; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n-1];
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