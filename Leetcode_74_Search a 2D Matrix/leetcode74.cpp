#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCnt = matrix.size(), colCnt = matrix[0].size();
        if(target > matrix[rowCnt - 1][colCnt - 1] || target < matrix[0][0]) return false;
        int low = 0, high = rowCnt - 1, mid = 0, fixedRow = 0;
        //search rows first element
        while(low <= high){
            mid = (low + high) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        fixedRow = high;
        //search cols
        low = 0;
        high = colCnt - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(matrix[fixedRow][mid] == target) return true;
            else if(matrix[fixedRow][mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
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