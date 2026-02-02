#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX, minY = INT_MAX, maxX = -1, maxY = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    minX = min(minX, j);
                    minY = min(minY, i);
                    maxX = max(maxX, j);
                    maxY = max(maxY, i);
                }
            }
        }

        if(minX == INT_MAX && minY == INT_MAX && maxX == -1 && maxY == -1) return 0;
        return (maxX - minX + 1) * (maxY - minY + 1);
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