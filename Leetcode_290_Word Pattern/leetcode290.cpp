#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> table;
        unordered_map<string, char> table2;
        string word = "";
        int j = 0, wordCnt = 0;
        for(int i = 0; i < pattern.length(); i++){
            if(j < s.length()) wordCnt++;
            while(j < s.length() && s[j] != ' '){
                word += s[j];
                j++;
            }
            j++;

            if(table.find(pattern[i]) == table.end()){
                if(table2.find(word) != table2.end()) return false;
                table.insert({pattern[i], word});
                table2.insert({word, pattern[i]});
            }
            else{
                if(table[pattern[i]] != word) return false;
            }
            word = "";
        }
        if(j < s.length()) return false;
        if(pattern.length() > wordCnt) return false;
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