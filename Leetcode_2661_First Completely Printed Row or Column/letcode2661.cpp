#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>


using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<pair<int, int>> numPos(rows * cols + 1, {0, 0});
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                numPos[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowBingo(rows, 0), colBingo(cols, 0);
        int i = 0;
        for(i; i < arr.size(); i++){
            if(++rowBingo[numPos[arr[i]].first] == cols) break;
            if(++colBingo[numPos[arr[i]].second] == rows) break;
            
        }
        return i;
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