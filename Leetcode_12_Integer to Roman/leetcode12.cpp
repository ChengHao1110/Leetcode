#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> roman;
        roman = {
            {1, "I"},
            {5, "V"},
            {10, "X"},
            {50, "L"},
            {100, "C"},
            {500, "D"},
            {1000, "M"}
        };
        string ans = "";
        int digit, ten = 1;
        while(num != 0){
            digit = num % 10;
            string part = "";
            if(digit == 4){
                part = roman[ten] + roman[ten * 5];
            }
            else if(digit == 9){
                part = roman[ten] + roman[ten * 10];
            }
            else if(digit >= 1 && digit <= 3){
                for(int i = 0; i < digit; i++) part += roman[ten];
            }
            else if(digit >= 5 && digit <= 8){
                for(int i = 0; i < digit - 5; i++) part += roman[ten];
                part = roman[ten * 5] + part;
            }
            ans = part + ans;
            num /= 10;
            ten *= 10;
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
        stringstream ss(input);
        int num;
        ss >> num;
        cout << sol.intToRoman(num) << endl;
    }
    testcase.close();
    return 0;
}