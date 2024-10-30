#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int change = 1, times = n, moveIdx = 0, r = 0, c = -1, num = 1;
        while(times){
            for(int i = 0; i < times; i++){
                r += dir[moveIdx].first;
                c += dir[moveIdx].second;
                ans[r][c] = num;
                num++;
            }
            change++;
            if(change == 2){
                change = 0;
                times--;
            }
            moveIdx++;
            if(moveIdx == 4) moveIdx = 0;
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
        int num;
        ss >> num;
        vector<vector<int>> ans = sol.generateMatrix(num);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}