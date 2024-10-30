#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(int i = 0; i < timePoints.size(); i++){
            int hours = stoi(timePoints[i].substr(0,2)), minutes = stoi(timePoints[i].substr(3,2));
            time.push_back(hours * 60 + minutes);
        }
        sort(time.begin(), time.end());
        int minTime = time[0] + 1440 - time[timePoints.size() - 1];
        for(int i = 0; i < timePoints.size() - 1; i++){
            minTime = min(minTime, time[i + 1] - time[i]);
            if(minTime == 0) return minTime;
        }
        return minTime;
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
        string s;
        vector<string> times;
        while(ss >> s) times.push_back(s);
        cout << sol.findMinDifference(times) << endl;
    }
    testcase.close();
    return 0;
}