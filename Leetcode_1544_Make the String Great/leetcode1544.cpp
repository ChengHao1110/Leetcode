#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<cmath>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        if(s.length() == 0) return s;
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && (abs(s[i] - st.top()) == 32)){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
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
    while(getline(testcase, input)){
        cout << sol.makeGood(input) << endl;
    }
    testcase.close();
    return 0;
}