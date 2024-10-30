#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        int count = 0;
        for(char ch : allowed) s.insert(ch);
        for(int i = 0; i < words.size(); i++){
            count++;
            for(char ch : words[i]){
                if(s.find(ch) == s.end()){
                    count--;
                    break;
                }
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

    }
    testcase.close();
    return 0;
}