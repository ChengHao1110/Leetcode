#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 && grid[0].size() < 3) return 0;
        unordered_set<int> possible = {492, 438, 816, 276, 834, 672, 618, 294};
        int ans = 0;
        for(int i = 1; i < grid.size() - 1; i++){
            for(int j = 1; j < grid[0].size() - 1; j++){
                if(grid[i][j] != 5) continue;
                if((grid[i-1][j-1] + grid[i+1][j+1]) == 10 && (grid[i-1][j+1] + grid[i+1][j-1]) == 10){
                    int v1 = grid[i-1][j-1] * 100 + grid[i-1][j] * 10 + grid[i-1][j+1];
                    int v2 = grid[i+1][j-1] * 100 + grid[i+1][j] * 10 + grid[i+1][j+1];
                    int v3 = grid[i-1][j-1] * 100 + grid[i][j-1] * 10 + grid[i+1][j-1];
                    int v4 = grid[i-1][j+1] * 100 + grid[i][j+1] * 10 + grid[i+1][j+1];
                    if(v1 != v2 && v3 != v4 && v1 != v3){
                        if(possible.find(v1) != possible.end() && 
                           possible.find(v2) != possible.end() &&
                           possible.find(v3) != possible.end() &&
                           possible.find(v4) != possible.end()){
                            ans++;
                        }
                    };
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
        stringstream ss(input);
        int row;
        ss >> row;
        ss.clear();
        ss.str("");
        vector<vector<int>> mat;
        for(int i = 0; i < row; i++){
            getline(testcase, input);
            ss << input;
            int num;
            vector<int> r;
            while(ss >> num) r.push_back(num);
            mat.push_back(r);
            ss.clear();
            ss.str("");
        }
        cout << "ans: " << sol.numMagicSquaresInside(mat) << endl;
    }
    testcase.close();
    return 0;
}