#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int rowCnt = 0, colCnt = 0;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rowCnt = grid1.size();
        colCnt = grid1[0].size();
        vector<vector<pair<int, int>>> islandInGrid2;

        for(int i = 0; i < rowCnt; i++){
            for(int j = 0; j < colCnt; j++){
                if(grid2[i][j] == 1){
                    vector<pair<int, int>> locations;
                    dfs(i, j, grid2, locations);
                    islandInGrid2.push_back(locations);
                } 
            }
        }
        /*
        for(int i = 0; i < islandInGrid2.size(); i++){
            for(int j = 0; j < islandInGrid2[i].size(); j++){
                cout << islandInGrid2[i][j].first << " " << islandInGrid2[i][j].second << endl;
            }
            cout << endl;
        }
        */
        int count = 0;
        for(int i = 0; i < islandInGrid2.size(); i++){
            bool isSub = true;
            for(int j = 0; j < islandInGrid2[i].size(); j++){
                int r = islandInGrid2[i][j].first, c = islandInGrid2[i][j].second;
                if(grid1[r][c] != 1){
                    isSub = false;
                    break;
                }
            }
            if(isSub) count++;
        }

        return count;
    }

    void dfs(int r, int c, vector<vector<int>> &grid, vector<pair<int, int>> &loc){
        loc.push_back({r, c});
        grid[r][c] = 0;
        for(int i = 0; i < dir.size(); i++){
            int nextR = r + dir[i].first, nextC = c + dir[i].second;
            if((nextR >= 0 && nextR < rowCnt && nextC >= 0 && nextC < colCnt) && grid[nextR][nextC] == 1){
                dfs(nextR, nextC, grid, loc);
            }
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
        vector<vector<int>> mat1, mat2;
        for(int i = 0; i < rowCnt; i++){
            getline(testcase, input);
            ss << input;
            vector<int> row;
            int num;
            while(ss >> num) row.push_back(num);
            mat1.push_back(row);
            ss.clear();
            ss.str("");
        }
        for(int i = 0; i < rowCnt; i++){
            getline(testcase, input);
            ss << input;
            vector<int> row;
            int num;
            while(ss >> num) row.push_back(num);
            mat2.push_back(row);
            ss.clear();
            ss.str("");
        }
        cout << sol.countSubIslands(mat1, mat2) << endl;
    }
    testcase.close();
    return 0;
}