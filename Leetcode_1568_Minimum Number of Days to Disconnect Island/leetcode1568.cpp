#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    int islandCount = 0;
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int gridRow = 0, gridCol = 0;

    int minDays(vector<vector<int>>& grid) {
        gridRow = grid.size();
        gridCol = grid[0].size();
        Initialize(gridRow, gridCol);
        // count island
        for(int i = 0; i < gridRow; i++){
            for(int j = 0; j < gridCol; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    islandCount++;
                    dfs(i, j, grid);
                }
            }
        }
        if(islandCount != 1) return 0;

        // change land to water
        for(int i = 0; i < gridRow; i++){
            for(int j = 0; j < gridCol; j++){
                if(grid[i][j] == 1){
                    Initialize(gridRow, gridCol);
                    grid[i][j] = 0;
                    bool notAllZero = true;
                    for(int k = 0; k < gridRow; k++){
                        for(int l = 0; l < gridCol; l++){
                            if(grid[k][l] == 1 && !visited[k][l]){
                                notAllZero = false;
                                islandCount++;
                                dfs(k, l, grid);
                            }
                        }
                    }
                    if(islandCount > 1 || notAllZero) return 1;
                    else grid[i][j] = 1;  
                }
            }
        }

        return 2;
    }

    void dfs(int r, int c, vector<vector<int>>& grid){
        visited[r][c] = true;
        for(int i = 0; i < dir.size(); i++){
            int nextRow = r + dir[i].first, nextCol = c + dir[i].second;
            if(nextRow >= 0 && nextRow < gridRow && nextCol >= 0 && nextCol < gridCol){ // inside grid
                if(grid[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]){
                    dfs(nextRow, nextCol, grid);
                }
            }
        }
        return;
    }

    void Initialize(int rowCount, int colCount){
        //initialize
        visited.clear();
        islandCount = 0;
        for(int i = 0; i < rowCount; i++){
            vector<bool> row(colCount, false);
            visited.push_back(row);
        }
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
        int rows;
        ss >> rows;
        ss.clear();
        ss.str("");
        vector<vector<int>> grid;
        for(int i = 0; i < rows; i++){
            vector<int> row;
            getline(testcase, input);
            ss << input;
            int num;
            while(ss >> num) row.push_back(num);
            grid.push_back(row);
            ss.clear();
            ss.str("");
        }
        cout << "ans: " << sol.minDays(grid) << endl;
    }
    testcase.close();
    return 0;
}