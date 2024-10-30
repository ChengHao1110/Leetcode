#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        CreateParentheses(0, n * 2, n, 0, 0, "", ans);
        return ans;
    }

    void CreateParentheses(int depth, int maxDepth, int count, int leftNum, int rightNum, string curStr, vector<string> &ans){
        if(leftNum >= rightNum && leftNum <= count && rightNum <= count){
            if(depth == maxDepth && leftNum == rightNum && leftNum == count){
                ans.push_back(curStr);
                return;
            }
            CreateParentheses(depth + 1, maxDepth, count, leftNum + 1, rightNum, curStr + '(', ans);
            CreateParentheses(depth + 1, maxDepth, count, leftNum, rightNum + 1, curStr + ')', ans);
        }
        return;
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
        vector<string> ans = sol.generateParenthesis(num);
        for(string s : ans) cout << s << endl;
        cout << endl;
    }
    testcase.close();
    return 0;
}