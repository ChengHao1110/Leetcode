#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string s : details){
            int sum = (s[11] - '0') * 10 + (s[12] - '0');
            if(sum > 60) count++;
        }
        return count;
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
    vector<string> data;
    Solution sol;
    while(getline(testcase, input)){
        data.push_back(input);
    }
    cout << "ans: " << sol.countSeniors(data) << endl;
    testcase.close();
    return 0;
}