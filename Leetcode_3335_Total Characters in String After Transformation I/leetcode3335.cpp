#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long m = 1000000007;
        long long ans = 0;
        vector<long long> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        while(t > 0){
            // find last
            int move = 0, idx;
            for(int i = 25; i >= 0; i--){
                if(freq[i] != 0){
                    move = 26 - i;
                    idx = i;
                    break;
                }
            }
            if(t < move) break;
            // update
            long long rec = freq[idx];
            freq[idx] = 0;
            for(int i = idx - 1; i >= 0; i--){
                if(freq[i] != 0){
                    freq[i + move] = freq[i];
                    freq[i] = 0;
                } 
            }
            freq[0] = (freq[0] + rec) % m;
            freq[1] = (freq[1] + rec) % m;
            t -= move;
        }
        for(long long ll : freq) ans = (ans + ll) % m;
        return ans;
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