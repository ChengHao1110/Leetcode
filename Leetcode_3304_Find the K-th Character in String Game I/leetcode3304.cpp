#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        vector<int> s(1024, 0);
        int curLen = 1;
        while(curLen < k){
            for(int i = 0; i < curLen; i++){
                s[curLen + i] = s[i] + 1;
            }
            curLen *= 2;
        }

        return 'a' + (s[k - 1] % 26);
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