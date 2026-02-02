#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(s == "+") st.push(a + b);
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else st.push(a / b);
            } 
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
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