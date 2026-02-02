#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    int rows = 0, cols = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    bool edge = false;

                    vector<pair<int, int>> group;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    group.push_back({i, j});
                    if(onEdge(i, j)) edge = true;

                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int newR = r + dir[k].first, newC = c + dir[k].second;
                            if(isValid(newR, newC) && !visited[newR][newC] && board[newR][newC] == 'O'){
                                q.push({newR, newC});
                                visited[newR][newC] = true;
                                group.push_back({newR, newC});
                                if(edge || onEdge(newR, newC)) edge = true;
                            }
                        }
                    }

                    if(!edge){
                        for(int k = 0; k < group.size(); k++){
                            board[group[k].first][group[k].second] = 'X';
                        }
                    }
                }
            }
        }
    }

    bool isValid(int x, int y){
        if(x >= 0 && y >= 0 && x < rows && y < cols) return true;
        else return false;
    }

    bool onEdge(int x, int y){
        if(x == 0 || y == 0 || x == rows - 1 || y == cols - 1) return true;
        else return false;
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