#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            if(s.length() % 2 == 1) continue;
            int l = 0, h = s.length() - 1, lSum = 0, hSum = 0;
            while(l < h){
                lSum += s[l] - '0';
                hSum += s[h] - '0';
                l++;
                h--;
            }
            if(lSum == hSum) ans++;
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