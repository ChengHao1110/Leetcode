#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<bitset>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        bitset<2501> b;
        b.set();
        int sum = 0, totalSum = 0, cnt = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                sum += grid[i][j];
                totalSum += (cnt++);
                b.flip(grid[i][j]);
            }
        }
        int r = 0, m = 0;
        r = b._Find_next(0);
        m = b._Find_next(r);
        if(sum > totalSum){
            return vector<int>{m, r};
        }
        else{
            return vector<int>{r, m};
        }
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
        int n = stoi(input);
        vector<vector<int>> grid;
        for(int i = 0; i < n; i++){
            getline(testcase, input);
            stringstream ss(input);
            int num;
            vector<int> arr;
            while(ss >> num) arr.push_back(num);
            grid.push_back(arr);
        }
        vector<int> ans = sol.findMissingAndRepeatedValues(grid);
        cout << ans[0] << " " << ans[1] << endl;
    }
    testcase.close();
    return 0;
}