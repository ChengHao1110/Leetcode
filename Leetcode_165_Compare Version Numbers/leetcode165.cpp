#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1 += ".";
        version2 += ".";

        string v1 = "", v2 = "";
        int idx1 = 0, idx2 = 0;
        while(1){
            v1 = frac(version1, idx1);
            v2 = frac(version2, idx2);
            if(v1 == "" && v2 == "") break;
            int num1, num2;
            if(v1 == "") num1 = 0;
            else num1 = stoi(v1);
            if(v2 == "") num2 = 0;
            else num2 = stoi(v2);

            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
        }
        return 0;
    }

    string frac(string s, int &idx){
        if(idx >= s.length()) return "";
        string result = "";
        while(s[idx] != '.'){
            result += s[idx];
            idx++;
        }
        idx++;
        return result;
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