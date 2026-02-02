#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<int> preZero(s.length(), 0), sufOne(s.length(), 0);
        preZero[0] = (s[0] == '0') ? 1 : 0;
        sufOne[s.length() - 1] = (s[s.length() - 1] == '1') ? 1 : 0;
        for(int i = 1; i < s.length(); i++){
            preZero[i] = preZero[i - 1] + ((s[i] == '0') ? 1 : 0);
            sufOne[s.length() - 1 - i] = sufOne[s.length() - i] + ((s[s.length() - 1 - i] == '1') ? 1 : 0);
        }
        int ans = -1;
        for(int i = 0; i < s.length() - 1; i++){
            ans = max(ans, preZero[i] + sufOne[i + 1]);
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