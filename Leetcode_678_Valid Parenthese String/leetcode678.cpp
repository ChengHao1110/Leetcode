#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<char> preprocess;
        vector<int> rightIdx;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                // pop lastIdx[-1] (
                if(!rightIdx.empty()){
                    preprocess.erase(preprocess.begin() + rightIdx.back());
                    rightIdx.pop_back();
                }
                else{
                    preprocess.push_back(s[i]);
                }
            }
            else if(s[i] == '('){
                preprocess.push_back(s[i]);
                rightIdx.push_back(preprocess.size() - 1);
            }
            else{ // *
                preprocess.push_back(s[i]);
            }
        }
        for(char c : preprocess) cout << c; cout << endl;
        if(preprocess.empty()) return true;

        stack<char> st;
        st.push(preprocess[0]);
        for(int i = 1; i < preprocess.size(); i++){
            switch (preprocess[i])
            {
            case '(':
                st.push('(');
                break;
            case ')':
                if(!st.empty()){
                    if(st.top() == '*') st.pop();
                    else st.push(')');
                }
                else{
                    st.push(')');
                }
                break;
            case '*':
                if(!st.empty()){
                    if(st.top() == '(') st.pop();
                    else st.push('*');
                }
                else{
                    st.push('*');
                }
                break;
            }
        }
        if(st.empty()) return true;
        while(!st.empty()){
            if(st.top() == '(' || st.top() == ')') return false;
            st.pop();
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

    string input;
    Solution sol;
    int idx = 1;
    while(getline(testcase, input)){
        cout << idx << endl;
        if(sol.checkValidString(input)) cout << "True" << endl;
        else cout << "False" << endl;
        idx++;
    }
    testcase.close();
    return 0;
}