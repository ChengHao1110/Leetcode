#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> freq(52, 0);
        for(char ch : word){
            if(ch >= 97){
                freq[ch-71]++; //-97 + 26
            }
            else{
                freq[ch-65]++;
            }
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0 && freq[i + 26] > 0) count++;
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
        cout << sol.numberOfSpecialChars(input) << endl;
    }
    testcase.close();
    return 0;
}