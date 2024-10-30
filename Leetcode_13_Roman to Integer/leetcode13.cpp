#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = 0, lastValue = roman[s[s.length() - 1]];
        ans = lastValue;
        if(s.length() == 1) return ans;
        for(int i = s.length() - 2; i >= 0; i--){
            if(roman[s[i]] < lastValue) ans -= roman[s[i]];
            else ans += roman[s[i]];
            lastValue = roman[s[i]];
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
        cout << sol.romanToInt(input) << endl;
    }
    testcase.close();
    return 0;
}