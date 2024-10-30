#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, -1), freq_copy(26, -1);
        for(char ch : s1){
            int idx = ch - 'a';
            if(freq[idx] == -1) freq[idx] = 1;
            else freq[idx]++;
        }
        freq_copy = freq;
        int left = 0, right = 0, length = s1.length();
        while(right < s2.length()){
            int idx = s2[right] - 'a';
            if(freq[idx] == -1){
                // not in s1, reset
                right++;
                left = right;
                freq = freq_copy;
                length = s1.length();
            }
            else if(freq[idx] == 0){
                // recover
                freq[idx]--;
                length--;
                while(freq[idx] == -1){
                    freq[s2[left] - 'a']++;
                    left++;
                    length++;
                }
                right++;
            }
            else{
                // continue
                freq[idx]--;
                length--;
                right++;
            }

            if(length == 0) return true;
        }
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