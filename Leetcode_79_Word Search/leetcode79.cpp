#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<set>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(DFS(board, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }

    bool DFS(vector<vector<char>> &board, int row, int col, int length, string word)
    {
        cout << endl;
        // check length
        if(length == word.length()) return true;
        // check if out of bound
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        // check if match
        if(board[row][col] != word[length]) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        int r[4] = {-1, 1, 0, 0}, c[4] = {0, 0, 1, -1};
        for(int idx = 0; idx < 4; idx++){
            if(DFS(board, row + r[idx], col + c[idx], length + 1, word)) return true;
        }
        board[row][col] = temp;
        return false;
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
    while(getline(testcase, input)){
        stringstream ss(input);
        int times;
        ss >> times;
        ss.clear();
        ss.str("");
        vector<vector<char>> board;
        for(int i = 0; i < times; i++){
            vector<char> line;
            getline(testcase, input);
            ss << input;
            char c;
            while(ss >> c) line.push_back(c);
            board.push_back(line);
            ss.clear();
            ss.str("");
        }
        getline(testcase, input);
        Solution sol;
        if(sol.exist(board, input)){
            cout << "TRUE" << endl << endl;
        }
        else{
            cout << "FALSE" << endl << endl;
        }
        
    }

    testcase.close();
    return 0;
}