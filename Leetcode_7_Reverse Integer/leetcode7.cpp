#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x == 0) return 0;
        string s = to_string(x);
        if(x < 0){
            neg = true;
            s.replace(s.begin(), s.begin() + 1, "");
        }
        for(int i = 0; i < s.length() / 2; i++){
            char tmp = s[i];
            s[i] = s[s.length() - 1 - i];
            s[s.length() - 1 - i] = tmp;
        }
        //cout << "reverse string: " << s << endl;
        // remove first 0
        int idx = 0;
        while(s[idx] == '0') idx++;
        if(idx >= 0) s.replace(s.begin(), s.begin() + idx, "");

        long long int sum = 0, dig = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            sum += (s[i] - '0') * dig;
            dig *= 10;
        }
        if(neg) sum *= -1;
        if(sum > INT_MAX || sum < INT_MIN) return 0;
        return sum;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        int num = stoi(input);
        cout << sol.reverse(num) << endl;
    }
    testcase.close();
    return 0;
}