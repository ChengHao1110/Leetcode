#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> table;
        string pre;
        for(int n : arr1){
            string s = to_string(n);
            pre = "";
            for(int i = 0; i < s.length(); i++){
                pre += s[i];
                if(table.find(pre) == table.end()) table.insert({pre, 1});
                else table[pre]++;
            }
        }

        int maxLength = 0;
        for(int n : arr2){
            string s = to_string(n);
            pre = "";
            for(int i = 0; i < s.length(); i++){
                pre += s[i];
                if(table.find(pre) != table.end()){
                    int len = pre.length();
                    maxLength = max(maxLength, len);
                }
            }
        }

        return maxLength;
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