#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        if(x >= y){
            s = GetScore(s, "ab", x, score, true);
            s = GetScore(s, "ba", y, score, false);
        }
        else{
            s = GetScore(s, "ba", y, score, true);
            s = GetScore(s, "ab", x, score, false);
        }
        return score;
    }

    string GetScore(string s, string match, int gain, int &score, bool newString){
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top() == match[0] && s[i] == match[1]){
                score += gain;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        s = "";
        if(newString){
            while(!st.empty()){
                s += st.top();
                st.pop();
            }
        }
        reverse(s.begin(), s.end());
        return s;
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