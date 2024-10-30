#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // to lower
        for(int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);

        // get alphabet string
        string newString = "";
        for(char &c : s) if( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) newString += c;

        cout << newString << endl;
        // check palindrome
        if(newString == "") return true;
        for(int i = 0; i < newString.length() / 2; i++){
            //cout << i << " " << newString[i] << " " << newString[newString.length() - 1 - i] << endl;
            if(newString[i] != newString[newString.length() - 1 - i]) return false;
        }
        return true;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    Solution sol;
    string data;
    while(getline(testcase, data)){
        cout << sol.isPalindrome(data) << endl;
    }
    return 0;
}