#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<bool>> visited(moveTime.size(), vector<bool>(moveTime[0].size(), false));
        vector<vector<int>> calTime(moveTime.size(), vector<int>(moveTime[0].size(), 0));
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({0, {0,0}});
        visited[0][0] = true;
        while(!pq.empty()){
            int curCost = pq.top().first, curRow = pq.top().second.first, curCol = pq.top().second.second;
            if(curRow == moveTime.size() - 1 && curCol == moveTime[0].size() - 1) return curCost;
            pq.pop();
            // top
            if(curRow - 1 > -1 && !visited[curRow - 1][curCol]){
                if(curCost >= moveTime[curRow - 1][curCol]) pq.push({curCost + 1, {curRow - 1, curCol}});
                else pq.push({moveTime[curRow - 1][curCol] + 1, {curRow - 1, curCol}});
                visited[curRow - 1][curCol] = true;
            }
            // down
            if(curRow + 1 < moveTime.size() && !visited[curRow + 1][curCol]){
                if(curCost >= moveTime[curRow + 1][curCol]) pq.push({curCost + 1, {curRow + 1, curCol}});
                else pq.push({moveTime[curRow + 1][curCol] + 1, {curRow + 1, curCol}});
                visited[curRow + 1][curCol] = true;
            }
            // left
            if(curCol - 1 > -1 && !visited[curRow][curCol - 1]){
                if(curCost >= moveTime[curRow][curCol - 1]) pq.push({curCost + 1, {curRow, curCol - 1}});
                else pq.push({moveTime[curRow][curCol - 1] + 1, {curRow, curCol - 1}});
                visited[curRow][curCol - 1] = true;
            }
            // right
            if(curCol + 1 < moveTime[0].size() && !visited[curRow][curCol + 1]){
                if(curCost >= moveTime[curRow][curCol + 1]) pq.push({curCost + 1, {curRow, curCol + 1}});
                else pq.push({moveTime[curRow][curCol + 1] + 1, {curRow, curCol + 1}});
                visited[curRow][curCol + 1] = true;
            }
        }
        return -1;
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