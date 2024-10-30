#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total = rows * cols - 1, times = 0, dir = 0, steps = 1;
        vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rIdx = rStart, cIdx = cStart;
        vector<int> first ={rIdx, cIdx};
        ans.push_back(first);
        // dir: 0(right), 1(down), 2(left), 3(up), times == 2 -> steps++
        while(total != 0){
            for(int i = 0; i < steps; i++){
                rIdx += move[dir].first;
                cIdx += move[dir].second;
                // check out of bound
                if(rIdx < rows && rIdx >= 0 && cIdx < cols && cIdx >= 0){
                    vector<int> grid ={rIdx, cIdx};
                    ans.push_back(grid);
                    total--;
                }
            }
            dir++;
            if(dir == 4) dir = 0;
            times++;
            if(times == 2){
                times = 0;
                steps++;
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
        int rows, cols, rStart, cStart;
        ss >> rows >> cols >> rStart >> cStart;
        vector<vector<int>> ans = sol.spiralMatrixIII(rows, cols, rStart, cStart);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}