#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> suffixMinChar(s.length());
        suffixMinChar[n - 1] = s[n - 1];
        for(int i = n - 2; i >= 0; i--) suffixMinChar[i] = min(s[i], suffixMinChar[i + 1]);
        string ans = "";
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == suffixMinChar[i]){
                while(!st.empty() && st.top() <= suffixMinChar[i]){
                    ans += st.top();
                    st.pop();
                }
                ans += s[i];
            }
            else{
                while(!st.empty() && st.top() <= suffixMinChar[i]){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
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

    }
    testcase.close();
    return 0;
}