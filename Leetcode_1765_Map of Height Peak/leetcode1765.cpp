#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> h(rows, vector<int>(cols, -1));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(isWater[i][j] == 1){
                    h[i][j] = 0;
                    pq.push({h[i][j], {i, j}});
                } 
            }
        }
        while(!pq.empty()){
            auto [val, pos] = pq.top();
            pq.pop();
            for(int i = 0; i < dir.size(); i++){
                int newRow = pos.first + dir[i].first, newCol = pos.second + dir[i].second;
                if(newRow >= 0 && newRow < rows && newCol >=0 && newCol < cols && h[newRow][newCol] == -1){
                    h[newRow][newCol] = val + 1;
                    pq.push({h[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        return h;
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