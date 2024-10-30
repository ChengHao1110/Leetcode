#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int level = 0;
        bool dirDown = true;
        vector<vector<char>> mat;
        for(int i = 0; i < numRows; i++){
            vector<char> list;
            mat.push_back(list);
        }
        for(char c : s){
            mat[level].push_back(c);
            if(dirDown){
                level++;
                if(level == numRows){
                    level = numRows - 2;
                    dirDown = false;
                }
            }
            else{
                level--;
                if(level < 0){
                    level = 1;
                    dirDown = true;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                ans += mat[i][j];
            }
        }
        return ans;
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
    string s;
    int numRows;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        ss >> s >> numRows;
        cout << sol.convert(s, numRows) << endl;
    }
    testcase.close();
    return 0;
}