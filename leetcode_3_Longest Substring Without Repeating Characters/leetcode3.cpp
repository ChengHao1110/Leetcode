#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int maxL = -1, tempL = 0, left = 0, right = 0;
        map<char, bool> existCh;
        while(right < s.length()){
            if(existCh.find(s[right]) != existCh.end()){
                // find duplicate
                // find same character
                while(s[left] != s[right]){
                    existCh.erase(s[left]);
                    tempL--;
                    left++;
                }
                left++;
            }
            else{
                // add new element
                existCh.insert({s[right], true});
                tempL++;
            }
            if(tempL > maxL) maxL = tempL;
            right++;
        }
        return maxL;
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
        cout << "ans: " << sol.lengthOfLongestSubstring(input) << endl;
    }
    testcase.close();
    return 0;
}