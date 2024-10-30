#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        //memory limit exceeded
        if(num.length() == k) return "0";
        //increasing monotonic stack
        vector<char> st;
        for(int i = 0; i < num.length(); i++){
            while(!st.empty() && st.back() > num[i] && k > 0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        // if k still larger than 0 原本就遞增
        while(k > 0){
            st.pop_back();
            k--;
        }
        // remove first 0
        int i = 0; 
        while (i < st.size() && st[i] == '0') i++; 
        st.erase(st.begin(), st.begin() + i);

        // vector to string
        string ans = "";
        for(char c : st) ans += c;
        
        // check empty 
        if(ans == "") return "0";
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
        stringstream ss(input);
        string num;
        int k;
        ss >> num >> k;
        cout << sol.removeKdigits(num, k) << endl;
    }
    testcase.close();
    return 0;
}