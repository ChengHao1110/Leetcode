#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        // remove following space
        int i = s.length() - 1;
        while(s[i] == ' ') i--;

        while(i >= 0){
            if(s[i] != ' '){
                word += s[i];
            }
            else if(word != ""){
                reverse(word.begin(), word.end());
                ans += word + " ";
                word = "";
            }
            i--;
        }
        if(word != ""){
            reverse(word.begin(), word.end());
            ans += word;
            return ans;
        } 
        if(ans[ans.length() - 1] == ' ') ans.erase(ans.end() - 1); 
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