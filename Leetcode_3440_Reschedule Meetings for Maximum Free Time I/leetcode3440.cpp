#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        if(startTime.size() == 1) return startTime[0] + eventTime - endTime[0];

        vector<pair<int, int>> freeTime;
        int n = startTime.size(), maxSpot = startTime[0];
        freeTime.push_back({startTime[0], 0});
        for(int i = 1; i < n; i++){
            freeTime.push_back({startTime[i] - endTime[i - 1], i});
            maxSpot = max(maxSpot, startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back({eventTime - endTime[n - 1], n});
        maxSpot = max(maxSpot, eventTime - endTime[n - 1]);

        if(maxSpot == 0) return 0;

        vector<pair<int, int>> freeTimeCopy = freeTime;
        sort(freeTime.begin(), freeTime.end(), greater<pair<int, int>>());
        int maxVal = maxSpot;
        for(int i = 0; i < startTime.size(); i++){
            int dur = endTime[i] - startTime[i];
            bool getMax = false;
            for(int j = 0; j < freeTime.size(); j++){
                if(freeTime[j].first >= dur){
                    if(freeTime[j].second == i || freeTime[j].second == i + 1) continue;
                    maxVal = max(maxVal, dur + freeTimeCopy[i].first + freeTimeCopy[i + 1].first);
                    break;
                }
                else{
                    break;
                }

            }
            if(!getMax){
                maxVal = max(maxVal, freeTimeCopy[i].first + freeTimeCopy[i + 1].first);
            }
        }

        return maxVal;
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