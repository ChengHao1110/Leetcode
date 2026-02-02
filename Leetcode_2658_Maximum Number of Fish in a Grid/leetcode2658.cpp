#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] > 0 && !visited[i][j]){
                    int val = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        val += grid[r][c];
                        for(int i = 0; i < 4; i++){
                            int nextR = r + dir[i].first, nextC = c + dir[i].second;
                            if(nextR < rows && nextR > -1 && nextC < cols && nextC > -1 && !visited[nextR][nextC] && grid[nextR][nextC] > 0){
                                q.push({nextR, nextC});
                                visited[nextR][nextC] = true;
                            }
                        }
                    }
                    ans = max(ans, val);
                }
            }
        }
        return ans;
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