#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ans = "1";
        for(int i = 0; i < n - 1; i++) ans = Compute(ans);
        return ans;
    }

    string Compute(string input){
        char curCh = input[0];
        int times = 1;
        string newStr = "";
        for(int i = 1; i < input.length(); i++){
            if(input[i] == curCh){
                times++;
            }
            else{
                newStr += to_string(times) + curCh;
                curCh = input[i];
                times = 1;
            }
        }
        newStr += to_string(times) + curCh;
        return newStr;
    }
};

int main(){
    string input;
    Solution sol;
    cout << sol.countAndSay(4) << endl;
    return 0;
}