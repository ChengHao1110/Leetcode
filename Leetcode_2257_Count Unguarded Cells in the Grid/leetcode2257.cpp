#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> mat;
    int remain = 0, rows = 0, cols = 0;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        mat.resize(m, vector<int>(n, false));
        rows = m;
        cols = n;
        remain = m * n - guards.size() - walls.size();

        for(int i = 0; i < guards.size(); i++) mat[guards[i][0]][guards[i][1]] = -1;

        for(int i = 0; i < walls.size(); i++) mat[walls[i][0]][walls[i][1]] = 2;

        for(int i = 0; i < guards.size(); i++){
            // up
            see(guards[i][0], guards[i][1], -1, 0);
            // down
            see(guards[i][0], guards[i][1], 1, 0);
            // right
            see(guards[i][0], guards[i][1], 0, 1);
            //left
            see(guards[i][0], guards[i][1], 0, -1);
        }

        return remain;
    }

    void see(int startR, int startC, int dirR, int dirC){
        int newR = startR + dirR, newC = startC + dirC;
        while(isValid(newR, newC) && mat[newR][newC] != -1 && mat[newR][newC] != 2){
            if(mat[newR][newC] == 0){
                remain--;
                mat[newR][newC] = 1;
            }
            newR += dirR;
            newC += dirC;
        }
    }

    bool isValid(int x, int y){
        if(x >= 0 && x < rows && y >=0 && y < cols) return true;
        return false;
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