#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if(numerator == 0) return "0";

        int sign = 1;
        if(numerator < 0){
            numerator = -numerator;
            sign *= -1;
        }

        if(denominator < 0){
            denominator = -denominator;
            sign *= -1;
        }
        

        long long front = (numerator >= denominator) ? numerator / denominator : 0;
        numerator = (numerator % denominator) * 10;
        if(numerator == 0){
            if(sign < 0) return "-" + to_string(front);
            else return to_string(front);
        }  

        unordered_map<long long, pair<int, int>> remain, pos;

        string back = "", duplicated = "";
        
        while(numerator != 0){
            remain[numerator].first++;
            if(remain[numerator].first > 1) break;
            remain[numerator].second = back.length();

            back += to_string(numerator / denominator);
            
            numerator = (numerator % denominator) * 10;
            if(numerator == 0) break;
        }

        string ans = "";
        if(numerator == 0){
            ans = to_string(front) + "." + back;
        }
        else{
            if(remain[numerator].second != 0){
                duplicated = back.substr(remain[numerator].second);
                back = back.substr(0, remain[numerator].second);
                ans = to_string(front) + "." + back + "(" + duplicated + ")";
            }
            else{
                ans = to_string(front) + ".(" + back + ")";
            }
        }

        if(sign < 0) return "-" + ans;
        else return ans;
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