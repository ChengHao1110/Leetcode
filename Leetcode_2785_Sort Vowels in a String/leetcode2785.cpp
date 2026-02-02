#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> idx;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowels.push_back(s[i]);
                idx.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end(), [](const char &c1, const char &c2){
            return c1 < c2;
        });

        for(int i = 0; i < vowels.size(); i++){
            s[idx[i]] = vowels[i];
        }

        return s;
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