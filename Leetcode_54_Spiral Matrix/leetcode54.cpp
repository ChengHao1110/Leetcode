#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowCnt = matrix.size() - 1, colCnt = matrix[0].size();
        int r = 0, c = -1, dirIdx = 0;
        vector<int> ans;
        while(rowCnt > 0 && colCnt > 0){
            if(dirIdx % 2 == 0){
                // move hor
                for(int i = 0; i < colCnt; i++){
                    r += dir[dirIdx].first;
                    c += dir[dirIdx].second;
                    ans.push_back(matrix[r][c]);
                }
                colCnt--;
            }
            else{
                // move ver
                for(int i = 0; i < rowCnt; i++){
                    r += dir[dirIdx].first;
                    c += dir[dirIdx].second;
                    ans.push_back(matrix[r][c]);
                }
                rowCnt--;
            }
            
            dirIdx++;
            if(dirIdx == 4) dirIdx = 0;
        }
        if(rowCnt == 0){
            for(int i = 0; i < colCnt; i++){
                r += dir[dirIdx].first;
                c += dir[dirIdx].second;
                ans.push_back(matrix[r][c]);
            }
        }
        else{
            for(int i = 0; i < rowCnt; i++){
                r += dir[dirIdx].first;
                c += dir[dirIdx].second;
                ans.push_back(matrix[r][c]);
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
        int rows;
        ss >> rows;
        vector<vector<int>> mat;
        while(rows--){
            getline(testcase, input);
            stringstream sss(input);
            vector<int> row;
            int num;
            while(sss >> num) row.push_back(num);
            mat.push_back(row);
        }
        vector<int> ans = sol.spiralOrder(mat);
        for(int n : ans) cout << n << " ";
        cout << endl;
    }
    testcase.close();
    return 0;
}