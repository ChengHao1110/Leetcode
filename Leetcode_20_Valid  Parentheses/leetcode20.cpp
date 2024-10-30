#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else{
                char ch = st.top();
                if(ch == '(' && s[i] == ')') st.pop();
                else if(ch == '[' && s[i] == ']') st.pop();
                else if(ch == '{' && s[i] == '}') st.pop();
                else{
                    st.push(s[i]);
                }
            }
        }
        return st.empty();
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
        if(sol.isValid(input)) cout << "True" << endl;
        else cout << "False";
    }
    testcase.close();
    return 0;
}