#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rowSet(9, unordered_set<int>()), colSet(9, unordered_set<int>()), gridSet(9, unordered_set<int>());
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    //rowSet
                    if(rowSet[i].find(board[i][j] - '0') == rowSet[i].end()) rowSet[i].insert(board[i][j] - '0');
                    else return false;
                    //colSet
                    if(colSet[j].find(board[i][j] - '0') == colSet[j].end()) colSet[j].insert(board[i][j] - '0');
                    else return false;
                    //gridSet
                    int idx = (i/3) * 3 + j/3;
                    if(gridSet[idx].find(board[i][j] - '0') == gridSet[idx].end()) gridSet[idx].insert(board[i][j] - '0');
                    else return false;
                }
            }
        }
        return true;
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