#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int len = 0, maxLen = 0, vowel = 0, left = 0, right = s.length() - 1;
        // a = 00001, e = 00010, i = 00100, o = 01000, u = 10000
        vector<int> preXorSum(s.length(), 0);
        preXorSum[0] = transform(s[0]);
        for(int i = 1; i < s.length(); i++){
            preXorSum[i] = preXorSum[i - 1] ^ transform(s[i]);
        }
        if(preXorSum[right] == 0) return right + 1;
        for(right; right >= 0; right--){
            if(preXorSum[right] == 0) maxLen = max(maxLen, right + 1);
            else{
                left = 0;
                while(left < right){
                    if((preXorSum[right] ^ preXorSum[left]) == 0){
                        maxLen = max(maxLen, right - left);
                        break;
                    } 
                    left++;
                }
            }
        }
        return maxLen;
    }

    int transform(char c){
        int num = 0;
        switch (c)
        {
        case 'a':
            num = 1;
            break;
        case 'e':
            num = 2;
            break;
        case 'i':
            num = 4;
            break;
        case 'o':
            num = 8;
            break;
        case 'u':
            num = 16;
            break;
        }
        return num;
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
        cout << sol.findTheLongestSubstring(input) << endl;
    }
    testcase.close();
    return 0;
}