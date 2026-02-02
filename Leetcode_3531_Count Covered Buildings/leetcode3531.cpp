#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> ySort(n + 1), xSort(n + 1);
        for(int i = 0; i < buildings.size(); i++){
            ySort[buildings[i][0]].push_back(buildings[i][1]);
            xSort[buildings[i][1]].push_back(buildings[i][0]);
        }
        for(int i = 1; i <= n; i++){
            sort(ySort[i].begin(), ySort[i].end());
            sort(xSort[i].begin(), xSort[i].end());
        }
        int ans = 0, yStart = 0, yEnd = 0, xStart = 0, xEnd = 0, curY = 0, curX = 0;
        for(int i = 0; i < buildings.size(); i++){
            curY = buildings[i][0];
            curX = buildings[i][1];
            yStart = xSort[curX][0];
            yEnd = xSort[curX].back();
            xStart = ySort[curY][0];
            xEnd = ySort[curY].back();
            if(curY > yStart && curY < yEnd && curX > xStart && curX < xEnd) ans++;
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