#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        set<char> usedChar;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end()){
                if(!usedChar.count(t[i])){
                    usedChar.insert(t[i]);
                }
                else{
                    return false;
                }  
                map[s[i]] = t[i];
            }
            else{
                if(map[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    while(getline(testcase, input)){
        stringstream ss(input);
        string word1, word2;
        ss >> word1 >> word2;
        Solution sol;
        cout << sol.isIsomorphic(word1, word2) << endl;
    }
    
    return 0;
}