#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, vector<int>> xObs, yObs;
        for(int i = 0; i < obstacles.size(); i++){
            if(xObs.find(obstacles[i][0]) == xObs.end()) xObs.insert({obstacles[i][0], vector<int>{obstacles[i][1]}});
            else xObs[obstacles[i][0]].push_back(obstacles[i][1]);
            if(yObs.find(obstacles[i][1]) == yObs.end()) yObs.insert({obstacles[i][1], vector<int>{obstacles[i][0]}});
            else yObs[obstacles[i][1]].push_back(obstacles[i][0]);
        }
        int x = 0, y = 0, max = 0, d = 0;
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                d++;
                if(d == 4) d = 0;
            }
            else if(commands[i] == -2){
                d--;
                if(d < 0) d = 3;
            }
            else{
                if(d % 2 == 0){
                    // move vertically
                    int nextY;
                    while(commands[i]--){
                        nextY = y + dir[d].second;
                        if(find(xObs[x].begin(), xObs[x].end(), nextY) == xObs[x].end()){
                            y = nextY;
                            if((x*x + y*y) > max) max = x*x + y*y;
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    // move horizontally
                    int nextX;
                    while(commands[i]--){
                        nextX = x + dir[d].first;
                        if(find(yObs[y].begin(), yObs[y].end(), nextX) == yObs[y].end()){
                            x = nextX;
                            if((x*x + y*y) > max) max = x*x + y*y;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        cout << x << " " << y << endl;
        return max;
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
        vector<int> arr;
        int num1, num2;
        while(ss >> num1) arr.push_back(num1);
        getline(testcase, input);
        stringstream sss(input);
        vector<vector<int>> obs;
        while(sss >> num1 >> num2){
            vector<int> o = {num1, num2};
            obs.push_back(o);
        }
        cout << sol.robotSim(arr, obs) << endl;
    }
    testcase.close();
    return 0;
}