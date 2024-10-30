#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0;
        // Transpose
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix[0].size(); j++){
                temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        // Reverse
        // swap col [0, n-1], [1, n-2]
        for(int j = 0; j < matrix[0].size() / 2; j++){
            for(int i = 0; i < matrix.size(); i++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix[0].size() - 1 - j];
                matrix[i][matrix[0].size() - 1 - j] = temp;    
            }
        }
    }
};

void Print(vector<vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

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
        int rowCnt = stoi(input);
        vector<vector<int>> matrix;
        while(rowCnt--){
            getline(testcase, input);
            stringstream ss(input);
            vector<int> row;
            int num;
            while(ss >> num) row.push_back(num);
            matrix.push_back(row);
        }
        cout << "Original: " << endl;
        Print(matrix);
        sol.rotate(matrix);
        cout << "Rotate: " << endl;
        Print(matrix);
    }
    testcase.close();
    return 0;
}

