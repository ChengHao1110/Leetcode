#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s[left] == '1'){
                while(right > left && s[right] != '0'){
                    right--;
                }
                swap += right - left;
                right--;
            }
            left++;
        }
        return swap;
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