#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word) freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int button = 1, ans = 0, times = 0;
        for(int num : freq){
            if(num == 0) return ans;
            if(times == 8){
                times = 0;
                button++;
            }
            ans += num * button;
            times++;
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
        cout << "ans: " << sol.minimumPushes(input) << endl;
    }
    testcase.close();
    return 0;
}