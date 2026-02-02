#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int oddMax = -1, evenMin = INT_MAX;
        vector<int> freq(26, 0);
        for(char ch : s) freq[ch - 'a']++;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;
            if(freq[i] % 2 == 0){
                evenMin = min(evenMin, freq[i]);
            }
            else{
                oddMax = max(oddMax, freq[i]);
            }
        }
        return oddMax - evenMin;
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