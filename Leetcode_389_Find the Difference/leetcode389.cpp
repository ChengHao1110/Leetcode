#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;
        for(char ch : t) freq[ch - 'a']--;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return 'a' + i;
        }
        return 'a';
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