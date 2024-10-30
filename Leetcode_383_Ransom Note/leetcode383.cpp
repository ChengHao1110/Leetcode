#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> table;
        for(char ch : magazine){
            if(table.find(ch) == table.end()) table.insert({ch, 1});
            else table[ch]++;
        }
        for(char ch : ransomNote){
            if(table.find(ch) == table.end()) return false;
            else if(table[ch] > 0) table[ch]--;
            else return false;
        }
        return true;
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