#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> maxDigit(str.length());
        maxDigit[str.length() - 1] = str.length() - 1;
        char curMax = str.back();
        int curIdx = str.length() - 1;
        for(int i = str.length() - 2; i >=0; i--){
            if(str[i] > curMax){
                curMax = str[i];
                curIdx = i;
            }
            maxDigit[i] = curIdx;
        }
        for(int i = 0; i < str.length(); i++){
            if(maxDigit[i] != i && str[i] != str[maxDigit[i]]){
                char tmp = str[i];
                str[i] = str[maxDigit[i]];
                str[maxDigit[i]] = tmp;
                return stoi(str);
            }
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
        cout << sol.maximumSwap(stoi(input)) << endl;
    }
    testcase.close();
    return 0;
}