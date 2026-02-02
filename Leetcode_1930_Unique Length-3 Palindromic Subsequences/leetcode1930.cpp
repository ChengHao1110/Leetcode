#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.length();
        vector<vector<bool>> table(26, vector<bool>(27, false)); // 0-25: a-z, 26: first character used 

        for(int i = 0; i < n - 2; i++){
            int firstIdx = s[i] - 'a';
            if(!table[firstIdx][26]){
                table[firstIdx][26] = true;
                for(int j = i + 1; j < n - 1; j++){
                    int secondIdx = s[j] - 'a';
                    if(!table[firstIdx][secondIdx]){
                        table[firstIdx][secondIdx] = true;
                        for(int k = j + 1; k < n; k++){
                            if(s[k] == s[i]){
                                ans++;
                                break;
                            }
                        }
                    }
                }
            }
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