#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> oper;
        stack<char> st;
        for(int i = 0; i < expression.length(); i++){
            switch(expression[i]){
                case '&':
                    oper.emplace_back('&');
                break;
                case '|':
                    oper.emplace_back('|');
                break;
                case '!':
                    oper.emplace_back('!');
                break;
                case 't':
                    st.push('t');
                break;
                case 'f':
                    st.push('f');
                break;
                case '(':{
                    st.push('(');
                }
                break;
                case ')':{
                    switch(oper.back()){
                        case '&':
                            st.push(parseAND(st));
                        break;
                        case '|':
                            st.push(parseOR(st));
                        break;
                        case '!':
                            st.push(parseNOT(st));
                        break;
                    }
                    oper.pop_back();
                }
                break;
                default:
                break;
            }
        }

        if(st.top() == 't') return true;
        else return false;
    }

    char parseAND(stack<char> &st){
        bool ans = true;
        while(st.top() != '(')
        {
            if(st.top() == 'f'){
                ans = false;
                while(st.top() != '('){
                    st.pop();
                }
            }
            else{
                st.pop();
            }
        }
        st.pop();
        if(ans) return 't';
        else return 'f';
    }

    char parseOR(stack<char> &st){
        bool ans = false;
        while(st.top() != '(')
        {
            if(st.top() == 't'){
                ans = true;
                while(st.top() != '('){
                    st.pop();
                }
            }
            else{
                st.pop();
            }
        }
        st.pop();
        if(ans) return 't';
        else return 'f';
    }

    char parseNOT(stack<char> &st){
        char cur = st.top();
        st.pop();
        st.pop(); // remove '('
        if(cur == 'f') return 't';
        else return 'f';
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
        if(sol.parseBoolExpr(input)) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
    testcase.close();
    return 0;
}