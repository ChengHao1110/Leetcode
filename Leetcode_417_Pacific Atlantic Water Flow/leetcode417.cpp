#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows, cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(); 
        cols = heights[0].size();
        
        vector<vector<pair<bool, bool>>> flow(rows, vector<pair<bool, bool>>(cols, {false, false})); // first = pacific, second = atlantic

        // first row
        for(int i = 0; i < cols; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({0, i});
            flow[0][i].first = true;
            visited[0][i] = true;
            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int newR = r + dir[j].first, newC = c + dir[j].second;
                    if(isValid(newR, newC) && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                        flow[newR][newC].first = true;
                        visited[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }    
        }

        // last row
        for(int i = 0; i < cols; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({rows - 1, i});
            flow[rows - 1][i].second = true;
            visited[rows - 1][i] = true;
            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int newR = r + dir[j].first, newC = c + dir[j].second;
                    if(isValid(newR, newC) && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                        flow[newR][newC].second = true;
                        visited[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }    
        }

        // first cols
        for(int i = 0; i < rows; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({i, 0});
            flow[i][0].first = true;
            visited[i][0] = true;
            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int newR = r + dir[j].first, newC = c + dir[j].second;
                    if(isValid(newR, newC) && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                        flow[newR][newC].first = true;
                        visited[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }    
        }

        // last cols
        for(int i = 0; i < rows; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            queue<pair<int, int>> q;
            q.push({i, cols - 1});
            flow[i][cols - 1].second = true;
            visited[i][cols - 1] = true;
            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int newR = r + dir[j].first, newC = c + dir[j].second;
                    if(isValid(newR, newC) && !visited[newR][newC] && heights[newR][newC] >= heights[r][c]){
                        flow[newR][newC].second = true;
                        visited[newR][newC] = true;
                        q.push({newR, newC});
                    }
                }
            }    
        }

        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(flow[i][j].first && flow[i][j].second) ans.push_back({i, j});
            }
        }
        
        return ans;
    }

    bool isValid(int r, int c){
        return (r >= 0) && (r < rows) && (c >= 0) && (c < cols);
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