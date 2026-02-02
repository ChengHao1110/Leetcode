#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for(char c : brokenLetters) broken[c - 'a'] = true;
        int i = 0, ans = 0;
        while(i < text.length()){
            if(text[i] == ' ') ans++;
            else{
                if(broken[text[i] - 'a']){
                    while(i < text.length() && text[i] != ' ') i++;
                    i++;
                }
            }
            i++;
        }
        if(i == text.length()) ans++;

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