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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> keep;
        stack<int> moveRight;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                moveRight.push(asteroids[i]);
            }
            else{
                if(!moveRight.empty()){
                    bool alive = true;
                    while(!moveRight.empty()){
                        int cur = moveRight.top();
                        if(abs(cur) < abs(asteroids[i])){
                            moveRight.pop();
                        }
                        else if (abs(cur) == abs(asteroids[i])){
                            moveRight.pop();
                            alive = false;
                            break;
                        }
                        else{
                            alive = false;
                            break;
                        }
                    }
                    if(alive) keep.push_back(asteroids[i]);
                }
                else{
                    keep.push_back(asteroids[i]);
                }
            }
        }
        vector<int> remain;
        while(!moveRight.empty()){
            remain.push_back(moveRight.top());
            moveRight.pop();
        }
        reverse(remain.begin(), remain.end());
        for(int n : remain) keep.push_back(n);
        return keep;
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
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        vector<int> ans = sol.asteroidCollision(arr);
        for(int n :ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}