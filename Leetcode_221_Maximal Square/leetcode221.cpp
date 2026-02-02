#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), maxVal = 0;

        vector<vector<int>> m(rows, vector<int>(cols, 0));
         for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                m[i][j] = matrix[i][j] - '0';
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(m[i][j] == 1 && i > 0 && j > 0){
                    m[i][j] = min(m[i - 1][j], min(m[i][j - 1], m[i - 1][j - 1])) + 1;
                }
                maxVal = max(maxVal, m[i][j]);
            }
        }

        return maxVal * maxVal;
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