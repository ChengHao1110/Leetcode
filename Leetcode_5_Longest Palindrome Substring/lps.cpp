#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;

        int maxLength = INT_MIN;
        int idx = 0;
        int case_palin = 0; // 0: odd, 1: same with right
        for(int i = 0; i < s.length(); i++){
            int length = 0;
            // odd
            while(((i - length) >= 0 && (i + length) < s.length())){
                if((s[i - length] == s[i + length])) length++;
                else break;
            }
            length--;
            if(2 * length + 1 > maxLength){
                maxLength = 2 * length + 1;
                idx = i;
                case_palin = 0;
            }

            // even same with right
            if((i + 1) < s.length()){
                length = 0;
                while(((i - length) >= 0 && (i + 1 + length) < s.length())){
                    if((s[i - length] == s[i + 1 + length])) length++;
                    else break;
                }
                length--;
                if(2 * length + 2 > maxLength){
                    maxLength = 2 * length + 2;
                    idx = i;
                    case_palin = 1;
                }
            }            
        }

        cout << idx << " " << maxLength << " " << case_palin << endl;;
        string ans = "";
        switch(case_palin){
            case 0:
                for(int start = idx - maxLength / 2; start <= idx + maxLength / 2; start++) ans += s[start];
                break;
            case 1:
                for(int start = idx + 1 - maxLength / 2; start <= idx + maxLength / 2; start++) ans += s[start];
                break;
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

    Solution sol;
    string data;
    while(getline(testcase, data)){
        cout << sol.longestPalindrome(data) << endl;
    }
}
