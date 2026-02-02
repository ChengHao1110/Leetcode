#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int i = s.length() - 1, length = 0, bits = floor(log2(k)) + 1;;
        long long sum = 0, base = 1;
        while(i >= 0){
            if(sum + base * (s[i] - '0') <= k){
                length++;
                sum += base * (s[i] - '0');
            }
            else{
                break;
            }
            i--;
            if(length < bits) base *= 2;
            else break;
        }

        while(i >= 0){
            if(s[i] == '0') length++;
            i--;
        }
        return length;
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