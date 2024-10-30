#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //solution
        int row = 0, col = grid[0].size() - 1, count = 0;
        while(row < grid.size() && col >= 0){
            if(grid[row][col] < 0){
                count += grid.size() - row;
                col--;
            }
            else{
                row++;
            }            
        }
        return count;
        //binary search
        /*
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            int l = 0, r = grid[0].size() - 1, m;
            while(l != r){
                m = l + (r - l) / 2;
                if(grid[i][m] >= 0){
                    l = m + 1;
                }
                else{
                    r = m;
                } 
            }
            if(grid[i][l] < 0) count += grid[0].size() - l;
        }
        return count;
        */
        //brute force
        /*
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] < 0) count++;
            }
        }
        return count;
        */
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    while(getline(testcase, input)){
        stringstream ss(input);
        int n, num;
        ss >> n;
        ss.clear();
        ss.str("");
        vector<vector<int>> grid;
        for(int i = 0; i < n; i++){
            vector<int> row;
            getline(testcase, input);
            ss << input;
            while(ss >> num) row.push_back(num);
            grid.push_back(row);
            ss.clear();
            ss.str("");
        }
        Solution sol;
        cout << sol.countNegatives(grid) << endl;
    }
    testcase.close();
    return 0;
}