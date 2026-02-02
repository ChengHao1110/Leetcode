#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int cur = 0, maxVal = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) cur++;
        }
        maxVal = cur;
        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i])) cur++;
            if(isVowel(s[i - k])) cur--;
            maxVal = max(maxVal, cur);
        }
        return maxVal;
    }

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
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