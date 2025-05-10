#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

typedef struct Cell{
    int cost = 0, row = 0, col = 0;
    bool moveOne = true;
};

class Compare{
public:
    bool operator()(const Cell &c1, const Cell &c2){
        return c1.cost < c2.cost;
    }
};

class Solution {
public:
    vector<vector<int>> moveTimeCopy;
    vector<vector<bool>> visited;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        moveTimeCopy = moveTime;
        visited.resize(moveTime.size(), vector<bool>(moveTime[0].size(), false));
        priority_queue< Cell, vector<Cell>, Compare > pq;
        Cell start;
        pq.push(start);
        visited[0][0] = true;
        while(!pq.empty()){
            Cell curCell = pq.top();
            if(curCell.row == moveTime.size() - 1 && curCell.col == moveTime[0].size() - 1) return curCell.cost;
            pq.pop();
            // top
            if(curCell.row - 1 > -1 && !visited[curCell.row - 1][curCell.col]){
                Cell nextCell = newCell(curCell, -1, 0);
                pq.push(nextCell);
            }
            // down
            if(curCell.row + 1 < moveTime.size() && !visited[curCell.row + 1][curCell.col]){
                Cell nextCell = newCell(curCell, 1, 0);
                pq.push(nextCell);
            }
            // left
            if(curCell.col - 1 > -1 && !visited[curCell.row][curCell.col - 1]){
                Cell nextCell = newCell(curCell, 0, -1);
                pq.push(nextCell);
            }
            // right
            if(curCell.col + 1 < moveTime[0].size() && !visited[curCell.row][curCell.col + 1]){
                Cell nextCell = newCell(curCell, 0, 1);
                pq.push(nextCell);
            }
            cout << curCell.row << " " << curCell.col << " " << curCell.cost << " " << curCell.moveOne << endl;
        }
        return -1;
    }

    Cell newCell(Cell curCell, int rowOffset, int colOffset){
        if(curCell.cost >= moveTimeCopy[curCell.row + rowOffset][curCell.col + colOffset]){
            if(curCell.moveOne) curCell.cost += 1;
            else curCell.cost += 2;
        } 
        else{
            if(curCell.moveOne) curCell.cost = moveTimeCopy[curCell.row + rowOffset][curCell.col + colOffset] + 1;
            else curCell.cost = moveTimeCopy[curCell.row + rowOffset][curCell.col + colOffset] + 2;
        }
        curCell.row += rowOffset;
        curCell.col += colOffset;
        curCell.moveOne = !curCell.moveOne;
        visited[curCell.row][curCell.col] = true;
        return curCell;
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