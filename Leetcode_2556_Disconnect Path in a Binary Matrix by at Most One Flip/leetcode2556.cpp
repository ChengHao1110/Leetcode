#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
private:
    int m, n;
    bool dfs(vector<vector<int>>& grid , int i , int j){
        if(i + 1 == m && j + 1 == n) return true;
        if(i == m || j == n || !grid[i][j]) return false;
        grid[i][j] = 0;
        return dfs(grid , i + 1 , j) || dfs(grid , i , j + 1);
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(!dfs(grid , 0 , 0)) return true;
        grid[0][0] = 1;
        return !dfs(grid , 0 , 0);
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