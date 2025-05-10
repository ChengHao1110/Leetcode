#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> table;
    int maxLength = 0;

    string findDifferentBinaryString(vector<string>& nums) {
        for(string s : nums) table.insert(s);
        string ans = "";
        bool find = false;
        maxLength = nums[0].length();
        bt("", ans, find);
        return ans;
    }

    void bt(string s, string &ans, bool &find){
        if(find) return;
        if(s.length() == maxLength){
            if(table.find(s) == table.end()){
                find = true;
                ans = s;
            }
            return;
        }
        s.push_back('0');
        bt(s, ans, find);
        s.pop_back();
        s.push_back('1');
        bt(s, ans, find);
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