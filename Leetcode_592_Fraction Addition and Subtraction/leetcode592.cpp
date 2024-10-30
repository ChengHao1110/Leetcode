#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> numerator, denominator;
        bool readDiv = false, readNeg = false;
        int curNum = 0;
        int totalDen = 1;
        if(expression[0] == '-') readNeg = true;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] >= '0' && expression[i] <= '9'){
                curNum = curNum*10 + expression[i] - '0';
            }
            if(expression[i] == '/'){
                (readNeg) ? numerator.push_back(-curNum) : numerator.push_back(curNum);
                curNum = 0;
                readDiv = true;               
            }
            if((expression[i] == '-' || expression[i] == '+') && readDiv){
                if(expression[i] == '-') readNeg = true;
                else readNeg = false;
                denominator.push_back(curNum);
                if(totalDen % curNum != 0) totalDen *= curNum;
                curNum = 0;
                readDiv = false;
            }            
        }
        denominator.push_back(curNum);
        if(totalDen % curNum != 0) totalDen *= curNum;
        cout << "totalDen: " << totalDen << endl;
        int totalNum = 0;
        for(int i = 0; i < numerator.size(); i++){
            totalNum += numerator[i] * (totalDen / denominator[i]);
        }
        cout << "totalNum: " << totalNum << endl;
        //gcd
        if(totalNum < 0){
            totalNum *= -1;
            readNeg = true;
        }
        else{
            readNeg = false;
        }
        int a = totalNum, b = totalDen;
        if(totalNum > totalDen){
            b = totalNum;
            a = totalDen;
        }
        while(a != 0){
            int temp = b % a;
            b = a;
            a = temp;
        }
        totalDen /= b;
        totalNum /= b;
        string ans = to_string(totalNum) + "/" + to_string(totalDen);
        if(readNeg) ans = "-" + ans;
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
        cout << sol.fractionAddition(input) << endl;
    }
    testcase.close();
    return 0;
}