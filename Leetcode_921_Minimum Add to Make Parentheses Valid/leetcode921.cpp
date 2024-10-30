#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, ans = 0;
        for(char ch : s){
            if(ch == '(') count++;
            else{
                if(count == 0){
                    ans++;
                }
                else count--;
            }
        }
        return ans + count;
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