#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    vector<int> dpArr;

    int minExtraChar(string s, vector<string>& dictionary) {
        dpArr.resize(50, -1);
        dict.clear();
        for(int i = 0; i < dictionary.size(); i++) dict.insert(dictionary[i]);
        return findExtra(s, 0);
    }

    int findExtra(string s, int idx){
        if(idx >= s.length()) return 0;
        if(dpArr[idx] != -1) return dpArr[idx];
        string tmp = "";
        int extra = s.length();

        for(int i = idx; i < s.length(); i++){
            tmp += s[i];
            cout << tmp << endl;
            if(dict.count(tmp) != 0){
                extra = min(extra, findExtra(s, i + 1));
            }
        }

        extra = min(extra, 1 + findExtra(s, idx + 1));
        
        dpArr[idx] = extra;
        cout << idx << " " << dpArr[idx] << endl;
        return dpArr[idx];
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
    while(getline(testcase, input)){
        string str = input, s;
        getline(testcase, input);
        stringstream ss(input);
        vector<string> dict;
        while(ss >> s) dict.push_back(s);
        Solution sol;
        cout << sol.minExtraChar(str, dict) << endl << endl;
    }
    testcase.close();
    return 0;
}