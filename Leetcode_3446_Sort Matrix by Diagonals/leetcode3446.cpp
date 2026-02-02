#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            vector<int> arr;
            for(int j = i, k = 0; j < rows && k < cols; j++, k++) arr.push_back(grid[j][k]);
            sort(arr.begin(), arr.end(), greater<int>());
            for(int l = 0, j = i, k = 0; l < arr.size(); l++, j++, k++) grid[j][k] = arr[l];
        }

        for(int i = 1; i < cols; i++){
            vector<int> arr;
            for(int j = i, k = 0; j < cols && k < rows; j++, k++) arr.push_back(grid[k][j]);
            sort(arr.begin(), arr.end());
            for(int l = 0, j = i, k = 0; l < arr.size(); l++, j++, k++) grid[k][j] = arr[l];
        }

        return grid;
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