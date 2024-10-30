#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowCount = matrix.size(), colCount = matrix[0].size(), ans = 0, h = 0, w = 0;
        vector<int> height(colCount + 1, 0); //last 0
        for(int i = 0; i < rowCount; i++){
            //record current height (row count 1)
            for(int j = 0; j < colCount; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int n : height) cout << n << " "; cout << endl;

            stack<int> st_idx; // store index
            //monotonic stack -> find width (col count 1)
            for(int j = 0; j < colCount + 1; j++){
                while(!st_idx.empty() && height[j] < height[st_idx.top()]){
                    h = height[st_idx.top()];
                    st_idx.pop();
                    if(st_idx.empty()) w = j;
                    else w = j - st_idx.top() - 1;
                    ans = max(ans , h * w);
                }
                st_idx.push(j);
            }
        }

        return ans;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<vector<char>> mat;
        int times;
        ss >> times;
        ss.clear();
        ss.str("");
        for(int i = 0; i < times; i++){
            getline(testcase, input);
            ss << input;
            char num;
            vector<char> row;
            while(ss >> num) row.push_back(num);
            mat.push_back(row);
            ss.clear();
            ss.str("");
        }
        cout << "Ans: " << sol.maximalRectangle(mat) << endl;
    }
    testcase.close();
    return 0;
}