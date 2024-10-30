#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> minRow, maxCol(matrix[0].size(), -1);
        for(int i = 0; i < matrix.size(); i++){
            int minR = INT_MAX;
            for(int j = 0; j < matrix[i].size(); j++){
                minR = min(minR, matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
            minRow.push_back(minR);
        }
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) ans.push_back(matrix[i][j]);
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
        int n, num;
        ss >> n;
        ss.clear();
        ss.str("");
        vector<vector<int>> mat;
        for(int i = 0; i < n; i++){
            getline(testcase, input);
            ss << input;
            vector<int> row;
            while(ss >> num) row.push_back(num);
            mat.push_back(row);
            ss.clear();
            ss.str("");
        }
        vector<int> ans = sol.luckyNumbers(mat);
        for(int a : ans) cout << a << " "; cout << endl;
    }
    testcase.close();
    return 0;
}