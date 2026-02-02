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
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> table;
        for(int i = 0; i < s.length(); i++){
            if(table.find(s[i]) == table.end()) table.insert({s[i], {i, i}});
            else table[s[i]].second = i;
        }
        vector<int> ans;
        int start = 0, curIdx = table[s[0]].second, i;
        while(start < s.length()){
            curIdx = table[s[start]].second;
            i = start + 1;
            while(i < curIdx + 1){
                curIdx = max(curIdx, table[s[i]].second);
                i++;
            }
            ans.push_back(i - start);
            start = i;
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