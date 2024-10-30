#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> sq(26, 0), tq(26, 0);
        for(int i = 0; i < s.length(); i++){
            sq[s[i]- 'a']++;
            tq[t[i]- 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(sq[i] != tq[i]) return false;
        }
        return true;
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