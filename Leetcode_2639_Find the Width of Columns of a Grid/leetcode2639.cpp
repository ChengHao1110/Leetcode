#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ans;
        for(int i = 0; i < cols; i++){
            int val = 0;
            for(int j = 0; j < rows; j++){
                val = max(val, (int)to_string(grid[j][i]).length());
            }
            ans.push_back(val);
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

    }
    testcase.close();
    return 0;
}