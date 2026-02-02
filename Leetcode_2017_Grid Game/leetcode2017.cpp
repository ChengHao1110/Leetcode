#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int cols = grid[0].size();
        vector<vector<long long>> arr(2, vector<long long>(cols, 0));
        arr[0][0] = grid[0][0];
        arr[1][0] = grid[1][0];
        for(int i = 1; i < cols; i++){
            arr[0][i] = arr[0][i - 1] + grid[0][i];
            arr[1][i] = arr[1][i - 1] + grid[1][i];
        }

        long long minVal = (arr[0][cols - 1] - arr[0][0]);
        for(int i = 1; i < cols; i++){
            minVal = min(minVal, max(arr[0][cols - 1] - arr[0][i], arr[1][i - 1]));
        }
        return minVal;
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