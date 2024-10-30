#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() == 0) return s;
        string rev_S = s;
        reverse(rev_S.begin(), rev_S.end());

        string ss = s + "#" + rev_S; //handle overlap, ex: aabba abbaa, aabb(aabbaa)
        vector<int> preArr(ss.length(), 0);
        int idx = 1, pos = 0;
        // use KMP algorithm
        while(idx < ss.length()){
            if(ss[idx] == ss[pos]){
                pos++;
                preArr[idx] = pos;
                idx++;
            }
            else{
                if(pos == 0){
                    preArr[idx] = 0;
                    idx++;
                }
                else{
                    pos = preArr[pos - 1];
                }
            }
        }
        int count = preArr.back();
        if(count >= rev_S.length()) return s;
        string ans = rev_S.substr(0, rev_S.length() - count) + s;
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
        cout << sol.shortestPalindrome(input) << endl;
    }
    testcase.close();
    return 0;
}