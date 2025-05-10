#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string pat = "";
    string ans = "";
    string smallestNumber(string pattern) {
        pat = pattern;
        bool find = false;
        for(int i = 1; i < 10; i++){
            vector<bool> used(10, false);
            used[i] = true;
            bt(0, to_string(i), used, find);
        }
        return ans;
    }

    void bt(int index, string s, vector<bool> used,bool &find){
        if(find) return;
        if(s.length() == pat.size() + 1){
            find = true;
            ans = s;
            return;
        }
        string ori = s;
        for(int i = 1; i < 10; i++){
            if(pat[index] == 'I'){
                if(i > s[index] - '0' && !used[i]){
                    s += to_string(i);
                    used[i] = true;
                    bt(index + 1, s, used, find);
                    s = ori;
                    used[i] = false;
                }
            }
            else{
                if(i < s[index] - '0' && !used[i]){
                    s += to_string(i);
                    used[i] = true;
                    bt(index + 1, s, used, find);
                    s = ori;
                    used[i] = false;
                }
            }
        }
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
        cout << sol.smallestNumber(input) << endl;
    }
    testcase.close();
    return 0;
}