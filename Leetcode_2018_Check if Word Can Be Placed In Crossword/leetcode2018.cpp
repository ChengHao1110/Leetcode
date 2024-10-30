#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rowCnt = 0, colCnt = 0;
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        rowCnt = board.size();
        colCnt = board[0].size();
        for(int i = 0; i < rowCnt; i++){
            for(int j = 0; j < colCnt; j++){
                if(board[i][j] == '#') continue;
                // top->down
                if(i == 0 || board[i-1][j] == '#'){
                    cout << "top->down" << endl;
                    if(find(i, j, 1, board, word)) return true;
                }
                // left->right
                if(j == 0 || board[i][j-1] == '#'){
                    cout << "left->right" << endl;
                    if(find(i, j, 0, board, word)) return true;
                }
                // 
                if(i == rowCnt-1 || board[i+1][j] == '#'){
                    cout << "down->top" << endl;
                    if(find(i, j, 3, board, word)) return true;
                }
                // right->left
                if(j == colCnt-1 || board[i][j+1] == '#'){
                    cout << "right->left" << endl;
                    if(find(i, j, 2, board, word)) return true;
                }
            }
        }
        return false;
    }

    bool find(int r, int c, int dir, vector<vector<char>>& board, string word){
        int wordLen = word.length();
        for(int i = 0; i < wordLen; i++){
            if(r >= 0 && r < rowCnt && c >= 0 && c < colCnt){
                if(board[r][c] == ' ' || board[r][c] == word[i]){
                    cout << board[r][c] << " ";
                    r += move[dir].first;
                    c += move[dir].second;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
        }
        cout << endl;
        //check if boardLen > wordlen
        if((r >= 0 && r < rowCnt && c >= 0 && c < colCnt) && board[r][c] != '#') return false;
        else return true;
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
        int num = stoi(input);
        vector<vector<char>> board;
        for(int i = 0; i < num; i++){
            getline(testcase, input);
            stringstream ss(input);
            vector<char> row;
            for(int i = 0; i < input.length(); i++) row.push_back(input[i]);
            board.push_back(row);
        }
        getline(testcase, input);
        if(sol.placeWordInCrossword(board, input)) cout << "T" << endl;
        else cout << "F" << endl;
    }
    testcase.close();
    return 0;
}