#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rowCnt = 0, colCnt = 0;
    int numIslands(vector<vector<char>>& grid) {
        rowCnt = grid.size();
        colCnt = grid[0].size();
        int isLandCnt = 0;
        for(int r = 0; r < rowCnt; r++){
            for(int c = 0; c < colCnt; c++){
                if(grid[r][c] == '1'){
                    isLandCnt++;
                    //dfs(r, c, grid);
                    bfs(r, c, grid);
                } 
            }
        }
        return isLandCnt;
    }

    void dfs(int r, int c, vector<vector<char>> &grid){
        grid[r][c] = '0';
        for(int i = 0; i < dir.size(); i++){
            int nextR = r + dir[i].first, nextC = c + dir[i].second;
            if((nextR >= 0 && nextR < rowCnt && nextC >= 0 && nextC < colCnt) && grid[nextR][nextC] == '1'){
                dfs(nextR, nextC, grid);
            }
        }
        return;
    }

    void bfs(int r, int c, vector<vector<char>> grid){
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            pair<int, int> cur = q.front();
            grid[cur.first][cur.second] = '0';
            for(int i = 0; i < dir.size(); i++){
                int nextR = cur.first + dir[i].first, nextC = cur.second + dir[i].second;
                if((nextR >= 0 && nextR < rowCnt && nextC >= 0 && nextC < colCnt) && grid[nextR][nextC] == '1'){
                    q.push({nextR, nextC});
                }
            }
            q.pop();
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
        int rowCnt;
        ss >> rowCnt;
        ss.clear();
        ss.str("");
        vector<vector<char>> mat;
        for(int i = 0; i < rowCnt; i++){
            getline(testcase, input);
            ss << input;
            vector<char> row;
            char ch;
            while(ss >> ch) row.push_back(ch);
            mat.push_back(row);
            ss.clear();
            ss.str("");
        }
        cout << sol.numIslands(mat) << endl;
    }
    testcase.close();
    return 0;
}