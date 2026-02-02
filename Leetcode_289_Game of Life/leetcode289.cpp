#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard = board;
        int rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int cnt = 0;
                for(int k = 0; k < dir.size(); k++){
                    int r = i + dir[k].first, c = j + dir[k].second;
                    if( r >= 0 && r < rows && c >= 0 && c < cols){
                        cnt += board[r][c];
                    }
                }
                if(board[i][j] == 0 && cnt == 3){
                    newBoard[i][j] = 1;
                }
                else{
                    if(cnt < 2 || cnt > 3) newBoard[i][j] = 0;
                }
            }
        }
        board = newBoard;
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