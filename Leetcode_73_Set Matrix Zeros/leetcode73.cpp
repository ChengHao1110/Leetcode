#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), r = 0, c = 0;
        bool isFirstRowZeros = false, isFirstColZeros = false;
        for(r = 0; r < rows; r++){
            if(matrix[r][0] == 0){
                isFirstColZeros = true;
                break;
            }
        }
        for(c = 0; c < cols; c++){
            if(matrix[0][c] == 0){
                isFirstRowZeros = true;
                break;
            }
        }
        for(r = 1; r < rows; r++){
            for(int c = 1; c < cols; c++){
                if(matrix[r][c] == 0){
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for(r = 1; r < rows; r++){
            if(matrix[r][0] == 0){
                for(int c = 0; c < cols; c++) matrix[r][c] = 0;
            }
        }
        for(c = 1; c < cols; c++){
            if(matrix[0][c] == 0){
                for(int r = 0; r < rows; r++) matrix[r][c] = 0;
            }
        }
        if(isFirstRowZeros) for(c = 0; c < cols; c++) matrix[0][c] = 0;
        if(isFirstColZeros) for(r = 0; r < rows; r++) matrix[r][0] = 0;
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