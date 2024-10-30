#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int length = 0;
        char lastCh = ' ';
        for(char ch : s){
            if(!st.empty() && ((lastCh == 'A' && ch == 'B') || (lastCh == 'C' && ch == 'D'))){
                st.pop();
                length--;
                if(st.empty()) lastCh = ' ';
                else lastCh = st.top();
            }
            else{
                st.push(ch);
                lastCh = ch;
                length++;
            } 
        }
        return length;
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
        cout << sol.minLength(input) << endl;
    }
    testcase.close();
    return 0;
}