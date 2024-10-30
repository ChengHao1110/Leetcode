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
        int button = 0, times = 1, ans = 0;
        for(int i = 0; i < word.length(); i++){
            ans += times;
            button++;
            if(button == 8){
                button = 0;
                times++;
            }
        }
        return ans;
    }

    int minimumPushes_old(string word) {
        vector<int> freq(26, 0);
        for(char ch : word){
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int button = 0, times = 1, ans = 0;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] != 0){
                ans += freq[i] * times;
                button++;
                if(button == 8){
                    button = 0;
                    times++;
                }
            }
            else break;
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
        cout << sol.minimumPushes(input) << endl;
    }
    testcase.close();
    return 0;
}