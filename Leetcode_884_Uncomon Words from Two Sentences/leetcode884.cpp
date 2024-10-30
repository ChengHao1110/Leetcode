#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, pair<int, int>> table;
        string word = "";
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != ' ') word += s1[i];
            else{
                if(table.find(word) == table.end()) table.insert({word, {1, 0}});
                else table[word].first++;
                word = "";
            }
        }
        if(table.find(word) == table.end()) table.insert({word, {1, 0}});
        else table[word].first++;
        word = "";
        for(int i = 0; i < s2.length(); i++){
            if(s2[i] != ' ') word += s2[i];
            else{
                if(table.find(word) == table.end()) table.insert({word, {0, 1}});
                else table[word].second++;
                word = "";
            }
        }
        if(table.find(word) == table.end()) table.insert({word, {0, 1}});
        else table[word].second++;
        vector<string> ans;
        for(unordered_map<string, pair<int, int>>::iterator iter = table.begin(); iter != table.end(); iter++){
            if((iter->second.first == 1 && iter->second.second == 0) || (iter->second.first == 0 && iter->second.second == 1)) ans.push_back(iter->first);
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
        string s1 = input;
        getline(testcase, input);
        vector<string> ans = sol.uncommonFromSentences(s1, input);
        for(string s : ans) cout << s << endl;
    }
    testcase.close();
    return 0;
}