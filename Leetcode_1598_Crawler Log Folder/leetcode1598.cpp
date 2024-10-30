#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for(string str : logs){
            if(str == "../"){
                if(level > 0) level--;
            }
            else if(str != "./"){
                level++;
            }
        }
        return level;
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