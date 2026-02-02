#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int fill = (s.length() % k == 0) ? 0 : k - (s.length() % k);
        for(int i = 0; i < fill; i++) s += 'x';
        vector<string> ans;
        int len = s.length(), start = 0;
        while(len > 0){
            string part = s.substr(start, k);
            ans.push_back(part);
            start += k;
            len -= k;
        }
        return ans;
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