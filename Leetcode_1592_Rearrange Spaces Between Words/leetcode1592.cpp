#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int idx = 0, space = 0;
        string word = "";
        vector<string> words;
        while(idx < text.length()){
            if(text[idx] == ' '){
                if(word != ""){
                    words.push_back(word);
                    word = "";
                }
                space++;
            }
            else{
                word += text[idx];
            }
            idx++;
        }
        //last word
        if(word != ""){
            words.push_back(word);
        }

        if(words.size() == 0) return text;
        if(words.size() == 1){
            string ans = words[0];
            for(int i = 0; i < space; i++){
                ans += ' ';
            }
            return ans;
        }
        
        int meanSpace = space / (words.size() - 1), remain = space % (words.size() - 1);
        string ans = words[0];
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < meanSpace; j++){
                ans += ' ';
            }
            ans += words[i];
        }
        for(int i = 0; i < remain; i++){
            ans += ' ';
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
        cout << sol.reorderSpaces(input) << "END" << endl;
    }
    testcase.close();
    return 0;
}