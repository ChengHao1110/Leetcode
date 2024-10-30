#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == ')'){
                if(!st.empty() && ( s[i] == ')' && st.top().first == '(' )){
                    st.pop();
                }
                else{
                    st.push(pair(s[i], i));
                }
            }
        }
        vector<int> removeIdx;
        while(!st.empty()){
            removeIdx.push_back(st.top().second);
            st.pop();
        }
        //for(int i : removeIdx) cout << i << " "; cout << endl;
        for(int i = 0; i < removeIdx.size(); i++){
            s.replace(removeIdx[i], 1, "");
            //cout << s << endl;
        }
        return s;
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
        cout << sol.minRemoveToMakeValid(input) << endl;
    }
    testcase.close();
    return 0;
}