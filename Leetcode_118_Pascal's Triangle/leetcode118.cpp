#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return vector<vector<int>>{{1}};
        if(numRows == 2) return vector<vector<int>>{{1}, {1, 1}};
        vector<vector<int>> mat = {{1}, {1, 1}};
        for(int i = 2; i < numRows; i++){
            vector<int> row = {1};
            for(int j = 0; j < mat[i - 1].size() - 1; j++){
                row.push_back(mat[i - 1][j] + mat[i - 1][j + 1]);
            }
            row.push_back(1);
            mat.push_back(row);
        }

        return mat;
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