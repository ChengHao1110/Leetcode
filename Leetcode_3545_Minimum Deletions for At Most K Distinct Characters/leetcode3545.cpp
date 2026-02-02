#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        set<char> alphabet;
        for(int i = 0; i < s.length(); i++){
            alphabet.insert(s[i]);
            freq[s[i] - 'a']++;
        }
        if(alphabet.size() <= k) return 0;
        sort(freq.begin(), freq.end());
        int idx = 0, ans = 0;
        while(freq[idx] == 0) idx++;
        for(int i = 0; i < alphabet.size() - k; i++){
            ans += freq[idx];
            idx++;
        }
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