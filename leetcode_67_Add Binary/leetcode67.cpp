#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s = b, l = a, ans = "";
        if(a.length() < b.length()){
            s = a;
            l = b;
        }
        int sL = s.length(), lIdx = l.length() - 1;
        bool carry = false;
        for(int i = s.length() - 1; i >= 0; i--, lIdx--){
            if(carry){
                if(s[i] == '1' && l[lIdx] == '1'){
                    ans = "1" + ans;
                }
                else if((s[i] == '0' && l[lIdx] == '1' ) || (s[i] == '1' && l[lIdx] == '0')){
                    ans = "0" + ans;
                }
                else{
                    ans = "1" + ans;
                    carry = false;
                }
            }
            else{
                if(s[i] == '1' && l[lIdx] == '1'){
                    ans = "0" + ans;
                    carry = true;
                }
                else if((s[i] == '0' && l[lIdx] == '1' ) || (s[i] == '1' && l[lIdx] == '0')){
                    ans = "1" + ans;
                }
                else{
                    ans = "0" + ans;
                }
            }    
        }
        for(int i = lIdx; i >= 0; i--){
            if(carry){
                if(l[i] == '1'){
                    ans = "0" + ans;
                }
                else{
                    ans = "1" + ans;
                    carry = false;
                }
            }
            else{
                ans = l[i] + ans;
            }
        }
        if(carry) ans = "1" + ans;
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
        stringstream ss(input);
        string a, b;
        ss >> a >> b;
        cout << sol.addBinary(a, b) << endl;
    }
    testcase.close();
    return 0;
}