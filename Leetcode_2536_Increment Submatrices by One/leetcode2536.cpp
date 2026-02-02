#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < queries.size(); i++){
            int startRow = queries[i][0], endRow = queries[i][2], startCol = queries[i][1], endCol = queries[i][3];
            for(int j = startCol; j <= endCol; j++){
                prefix[startRow][j]++;
                prefix[endRow + 1][j]--;
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            ans[0][i] = prefix[0][i];
            for(int j = 1; j < n; j++){
                ans[j][i] = ans[j - 1][i] + prefix[j][i];
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

    }
    testcase.close();
    return 0;
}