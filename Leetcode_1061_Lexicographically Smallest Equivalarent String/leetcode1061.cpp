#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<char> parent;
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i = 0; i < 26; i++) parent[i] = ('a' + i);
        for(int i = 0; i < s1.length() ; i++){
            Union(s1[i], s2[i]);
        }
        /*
        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            cout << ch << " : " << parent[i] << endl;
        }
        */
        string ans = "";
        for(int i = 0; i < baseStr.length(); i++){
            ans += Find(baseStr[i]);
        }
        return ans;
    }

    char Find(char ch){
        int idx = ch - 'a';
        if(parent[idx] == ch) return ch;
        else return parent[idx] = Find(parent[idx]);
    }

    void Union(char ch1, char ch2){
        char p1 = Find(ch1), p2 = Find(ch2);
        if(p1 == p2) return;
        else if(p1 < p2){
            parent[p2 - 'a'] = p1;
        }
        else{
            parent[p1 - 'a'] = p2;
        }
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