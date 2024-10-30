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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for(int i = 0; i < strs.size(); i++){
            string ori = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(table.find(strs[i]) == table.end()) table.insert({strs[i], vector<string> {ori}});
            else table[strs[i]].push_back(ori);
        }
        unordered_map<string, vector<string>>::iterator iter = table.begin();
        vector<vector<string>> ans;
        for(iter; iter != table.end(); iter++){
            ans.push_back(iter->second);
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