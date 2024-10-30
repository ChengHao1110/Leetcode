#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include <stack>


using namespace std;

class Robot{
public:
    int id, pos;
    char dir;
    Robot(int id, int pos, char dir){
        this->id = id;
        this->pos = pos;
        this->dir = dir;
    }
};

bool PosCmp(Robot r1, Robot r2){
    return r1.pos < r2.pos;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        // initial
        vector<Robot> robots;
        for(int i = 0; i < positions.size(); i++){
            Robot r(i, positions[i], directions[i]);
            robots.push_back(r);
        }
        sort(robots.begin(), robots.end(), PosCmp);
        //for(int i = 0; i < robots.size(); i++) cout << robots[i].pos << " " << robots[i].id << " " << robots[i].dir << endl;

        // Check collision
        stack<Robot> collision;
        for(int i = 0; i < robots.size(); i++){
            if(robots[i].dir == 'R') collision.push(robots[i]);
            else{
                while(!collision.empty() && healths[robots[i].id] > 0){
                    Robot rival = collision.top();
                    collision.pop();
                    int remainHp = healths[robots[i].id] - healths[rival.id];
                    //cout << rival.id << " and " << robots[i].id << " collision" << endl;
                    if(remainHp > 0){
                        //cout << robots[i].id << " win" << endl;
                        healths[robots[i].id]--;
                        healths[rival.id] = 0;
                    }
                    else if(remainHp < 0){
                        //cout << rival.id << " win" << endl;
                        healths[robots[i].id] = 0;
                        healths[rival.id]--;
                        collision.push(rival);
                    }
                    else{
                        //cout << "All lose" << endl;
                        healths[robots[i].id] = 0;
                        healths[rival.id] = 0;
                    }
                }
            }
        }
        for(int i = 0; i < robots.size(); i++){
            if(healths[i] > 0) ans.push_back(healths[i]);
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
        int num;
        vector<int> pos, hp, ans;
        //read position
        while(ss >> num) pos.push_back(num);
        ss.clear();
        ss.str("");
        //read health
        getline(testcase, input);
        ss << input;
        while(ss >> num) hp.push_back(num);
        //read
        getline(testcase, input);
        ans = sol.survivedRobotsHealths(pos, hp, input);
        for(int a : ans) cout << a << " "; cout << endl;
    }
    testcase.close();
    return 0;
}