#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char c : word) freq[c - 'a']++;
        int minDel = INT_MAX;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                int del = 0;
                for(int j = 0; j < 26; j++){
                    if(freq[j] < freq[i]) del += freq[j];
                    else if(freq[j] > freq[i] + k){
                        del += (freq[j] - freq[i] - k);
                    }
                }
                minDel = min(minDel, del);
            }
        }

        return minDel;
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