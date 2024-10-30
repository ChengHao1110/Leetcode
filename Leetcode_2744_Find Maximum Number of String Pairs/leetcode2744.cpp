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
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> table;
        string revStr;
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            revStr = words[i];
            reverse(revStr.begin(), revStr.end());
            if(table.find(revStr) != table.end()){
                count++;
            }
            else{
                table.insert(words[i]);
            }
        }
        return count;
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
        stringstream ss(input);
        string s;
        vector<string> arr;
        while(ss >> s) arr.push_back(s);
        cout << sol.maximumNumberOfStringPairs(arr) << endl;
    }
    testcase.close();
    return 0;
}