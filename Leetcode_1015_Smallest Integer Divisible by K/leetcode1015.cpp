#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<int> s(k, 0);
        int n = 1 % k, cnt = 1;
        while(n != 0){
            if(s[n] == 1) return -1;
            else s[n]++;
            n = (n * 10 + 1) % k;
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