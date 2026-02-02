#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && st.top().first == s[i]){
                if(++st.top().second == k) st.pop();
            }
            else{
                st.push({s[i], 1});
            }
        }
        if(st.empty()) return "";
        string ans = "";
        while(!st.empty()){
            string s(st.top().second, st.top().first);
            ans = s + ans;
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