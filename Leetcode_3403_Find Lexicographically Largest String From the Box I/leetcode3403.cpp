#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.length(), maxSplitLen = n - numFriends + 1;
        string ans = word.substr(0, maxSplitLen);
        for(int i = 1; i < n; i++){
            string s;
            if(i + maxSplitLen - 1 < n){
                s = word.substr(i, maxSplitLen);
            }
            else{
                s = word.substr(i);
            }
            ans = LargerString(ans, s);
        }
        return ans;
    }

    string LargerString(string s1, string s2){
        int s1Idx = 0, s2Idx = 0;
        while(s1Idx < s1.length() && s2Idx < s2.length()){
            if(s1[s1Idx] > s2[s2Idx]) return s1;
            else if(s1[s1Idx] < s2[s2Idx]) return s2;
            else{
                s1Idx++;
                s2Idx++;
            }
        }
        if(s1.length() > s2.length()) return s1;
        else if(s1.length() < s2.length()) return s2;
        else return s1;
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