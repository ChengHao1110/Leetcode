#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxCount = 0;
        for(char c : s){
            if(c == '('){
                count++;
                if(maxCount < count) maxCount = count;
            }
            if(c == ')') count--;
        }
        return maxCount;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }
    
    string input;
    while(getline(testcase, input)){
        Solution sol;
        cout << sol.maxDepth(input) << endl;
    }
    testcase.close();
    return 0;
}