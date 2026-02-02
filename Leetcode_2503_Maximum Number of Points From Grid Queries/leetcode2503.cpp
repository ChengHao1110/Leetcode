#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Cell{
public:
    int r, c, v;
    Cell(int row, int col, int val){
        r = row;
        c = col;
        v = val; 
    }
};

class Compare {
public:
    bool operator()(const Cell &c1, const Cell &c2)
    {
        if (c1.v > c2.v)
            return true;
        else
            return false;
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < queries.size(); i++) sortedQueries.push_back({queries[i], i});
        sort(sortedQueries.begin(), sortedQueries.end());

        int cnt = 0;
        vector<int> ans(queries.size());

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue< Cell, vector<Cell>, Compare> pq;
        Cell start(0, 0, grid[0][0]);
        visited[0][0] = true;
        pq.push(start);
        for(int i = 0; i < sortedQueries.size(); i++){
            while(!pq.empty() && pq.top().v < sortedQueries[i].first){
                auto cell = pq.top();
                pq.pop();
                cnt++;
                // up
                if(cell.r - 1 >= 0 && !visited[cell.r - 1][cell.c]){
                    Cell c(cell.r - 1, cell.c, grid[cell.r - 1][cell.c]);
                    visited[cell.r - 1][cell.c] = true;
                    pq.push(c);
                }
                // down
                if(cell.r + 1 < rows && !visited[cell.r + 1][cell.c]){
                    Cell c(cell.r + 1, cell.c, grid[cell.r + 1][cell.c]);
                    visited[cell.r + 1][cell.c] = true;
                    pq.push(c);
                }
                // left
                if(cell.c - 1 >= 0 && !visited[cell.r][cell.c - 1]){
                    Cell c(cell.r, cell.c - 1, grid[cell.r][cell.c - 1]);
                    visited[cell.r][cell.c - 1] = true;
                    pq.push(c);
                }
                //right
                if(cell.c + 1 < cols && !visited[cell.r][cell.c + 1]){
                    Cell c(cell.r, cell.c + 1, grid[cell.r][cell.c + 1]);
                    visited[cell.r][cell.c + 1] = true;
                    pq.push(c);
                }
            }
            ans[sortedQueries[i].second] = cnt;
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
        int n = stoi(input), num;;
        vector<vector<int>> grid;
        while(n--){
            getline(testcase, input);
            stringstream ss(input);
            vector<int> arr;
            while(ss >> num) arr.push_back(num);
            grid.push_back(arr);
        }
        getline(testcase, input);
        stringstream sss(input);
        vector<int> q;
        while(sss >> num) q.push_back(num);
        vector<int> ans = sol.maxPoints(grid, q);
        for(int a : ans) cout << a << " "; cout << endl;
    }
    testcase.close();
    return 0;
}