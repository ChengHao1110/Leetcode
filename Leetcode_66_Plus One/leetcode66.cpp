#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        digits[digits.size() - 1]++;
        if(digits[digits.size() - 1] == 10){
            digits[digits.size() - 1] = 0;
            carry = true;
        }
        for(int i = digits.size() - 2; i >= 0; i--){
            if(carry){
                digits[i]++;
            }
            if(digits[i] == 10){
                digits[i] = 0;
                carry = true;
            }
            else{
                return digits;
            }            
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
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
        vector<int> arr, ans;
        int num;
        stringstream ss(input);
        while(ss >> num) arr.push_back(num);
        ans = sol.plusOne(arr);
        for(int n : ans) cout << n; cout << endl;
    }
    testcase.close();
    return 0;
}