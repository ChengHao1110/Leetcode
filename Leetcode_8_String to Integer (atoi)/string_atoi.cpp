#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int maxNum = 2147483647;
const int minNum = -2147483648;

class Solution {
public:
    // leetcode
    int myAtoi(string s) {
        bool getNum = false, getSign = false;
        char sign = '+';
        string number = "";
        for(char& c : s){
            if(!getNum){
                // space
                if(c == ' '){
                    if(getSign){
                        number = "0";
                        break;
                    }
                    continue;
                }
                // pos sign
                if(c == '+'){
                    if(!getSign){
                        getSign = true;
                    }
                    else{
                        number = "0";
                        break;
                    }
                    continue;
                }
                // neg sign
                if(c == '-'){
                    if(!getSign){
                        getSign = true;
                        sign = '-';
                    }
                    else{
                        number = "0";
                        break;
                    }
                    continue;
                }
                // 0-9 : [48-57] Ascii
                if(c >= '0' && c <= '9'){ 
                    getNum = true;
                    number += c;
                    continue;
                }
                // a-z and .
                if((c >= 'a' && c <= 'z') || c == '.'){
                    number = "0";
                    break;
                }
            }
            else{
                if(c >= 48 && c <= 57){
                    number += c;
                }
                else{
                    break;
                }
            }
        }

        //cout << number << endl;

        //remove front zeros
        int index = 0;
        for(char &c :number){
            if(c == '0') index++;
            else break;
        }
        //copy
        string trueNumber = "";
        for(int i = index; i < number.length(); i++) trueNumber += number[i];

        int digitNum = trueNumber.length();

        // check length
        if(digitNum > 10){
            if(sign == '+') return maxNum;
            if(sign == '-') return minNum;
        }

        long long int sum = 0;
        for(int i = digitNum; i > 0; i--){
            long long int ten = 1;
            for(int j = 0; j < i - 1; j++){
                ten *= 10;
            }
            sum += (trueNumber[digitNum - i] - '0') * ten;
        }
        //cout << sum << endl;
        if(sign == '-') sum = sum * -1;
        
        if(sum > maxNum) sum = maxNum;
        if(sum < minNum) sum = minNum;
        return sum;
    }

    int myAtoi_other(std::string s) {
        int i = 0;
        // Step 1: Read and ignore leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for '+' or '-' to determine sign
        int sign = 1;
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Step 3: Read characters until non-digit or end of input
        long long result = 0; // Use long long to handle potential overflow
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            // Step 4: Check for integer overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        // Step 5: Apply sign and return the result
        return result * sign;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    Solution sol;
    string data;
    while(getline(testcase, data)){
        cout << sol.myAtoi(data) << endl;
    }

    return 0;
}