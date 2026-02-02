#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool vowel = false, consonant = false;
        for(int i = 0; i < word.length(); i++){
            if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')){
                if(isVowel(word[i])){
                    vowel = true;
                }
                else{
                    if(!consonant) consonant = true;
                }
            }
            else if(word[i] >= '0' && word[i] <= '9'){
                continue;
            }
            else{
                return false;
            }
        }
        return vowel && consonant;
    }

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
            return true;
        }
        return false;
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