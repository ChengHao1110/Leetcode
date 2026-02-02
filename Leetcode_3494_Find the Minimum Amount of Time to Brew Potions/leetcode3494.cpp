#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> finishTime(skill.size(), 0);
        for(int i = 0; i < mana.size(); i++){
            long long curTime = 0;
            for(int j = 0; j < skill.size(); j++){
                curTime = max(curTime, finishTime[j]) + skill[j] * mana[i];
            }
            finishTime[skill.size() - 1] = curTime;
            for(int j = skill.size() - 2; j >= 0; j--){
                finishTime[j] = finishTime[j + 1] - skill[j + 1] * mana[i];
            }
        }

        return finishTime[skill.size() - 1];
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