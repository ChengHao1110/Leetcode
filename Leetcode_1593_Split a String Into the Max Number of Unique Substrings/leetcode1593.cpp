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
    int maxCount;
    string str;
    int maxUniqueSplit(string s) {
        maxCount = 0;
        str = s;
        unordered_set<string> table;
        BT(0, table, 0);
        return maxCount;
    }

    void BT(int startPos, unordered_set<string> &table, int matchLen){
        if(matchLen == str.length()){
            //cout << "table: " << endl;
            //for(unordered_set<string>::iterator iter = table.begin(); iter != table.end(); iter++) cout << *iter << endl;
            maxCount = max(maxCount, static_cast<int>(table.size()));
            return;
        }
        string cur = "";
        for(int i = startPos; i < str.length(); i++){
            cur += str[i];
            if(table.find(cur) == table.end()){
                //cout << "add: " << cur << endl;
                table.insert(cur);
                matchLen += cur.length();
                BT(i + 1, table, matchLen);
                table.erase(cur);
                matchLen -= cur.length();
                //cout << "erase: " << cur << endl;
            }
        }
        return;
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
        cout << sol.maxUniqueSplit(input) << endl;
    }
    testcase.close();
    return 0;
}