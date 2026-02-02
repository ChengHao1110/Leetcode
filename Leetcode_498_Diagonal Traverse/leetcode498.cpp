#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 1}, {1, -1}};
    int curR = 0, curC = 0, d = 0, rows, cols;
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        vector<int> ans;
        ans.push_back(mat[curR][curC]);
        while(curR != rows - 1 || curC != cols - 1){
            curR += dir[d].first;
            curC += dir[d].second;
            if(isValid(curR, curC)) ans.push_back(mat[curR][curC]);
            else{
                if(d == 0){
                    curR++;
                    d = 1;
                    while(!isValid(curR, curC)){
                        curR += dir[d].first;
                        curC += dir[d].second;
                    }
                }
                else{
                    curC++;
                    d = 0;
                    while(!isValid(curR, curC)){
                        curR += dir[d].first;
                        curC += dir[d].second;
                    }
                }
                ans.push_back(mat[curR][curC]);
            }
        }
        return ans;
    }

    bool isValid(int r, int c){
        return r >= 0 && c >= 0 && r < rows && c < cols;
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