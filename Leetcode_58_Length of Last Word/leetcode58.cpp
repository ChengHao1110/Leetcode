#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include <string.h> // strtok()

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        /*
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        return words.back().length();
        */
        char *newString = new char[s.length()];
        vector<string> words;
        for(int i = 0; i < s.length(); i++) newString[i] = s[i];
        char *word;
        word = strtok(newString, " ");
        while(word != NULL){
            words.push_back(word);
            word = strtok(NULL, " ");
        }
        return words.back().length();
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string data;
    Solution sol;
    while(getline(testcase, data)){
        cout << "last word length: " << sol.lengthOfLastWord(data) << endl;
    }
    return 0;
}