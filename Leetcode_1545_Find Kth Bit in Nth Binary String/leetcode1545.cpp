#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        string s = "0", inv;
        for(int i = 1; i < n; i++){
            s = s + "1" + Reverse(Invert(s));
            cout << s << endl;
        }
        return s[k - 1];
    }

    string Invert(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return s;
    }

    string Reverse(string s){
        reverse(s.begin(), s.end());
        return s;
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
        int n, k;
        ss >> n >> k;
        cout << sol.findKthBit(n, k) << endl;
    }
    testcase.close();
    return 0;
}