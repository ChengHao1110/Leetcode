#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;
        if(startTime[0] > 0) freetime.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            freetime.push_back(startTime[i] - endTime[i - 1]);
        }
        if(endTime[endTime.size() - 1] < eventTime) freetime.push_back(eventTime - endTime[endTime.size() - 1]);

        int val = 0, maxVal = 0, l = 0, r = 0;
        if(freetime.size() < k + 1){
            for(r; r < freetime.size(); r++){
                maxVal += freetime[r];
            }
        }
        else{
            for(r; r < k + 1; r++){
                val += freetime[r];
            }
            maxVal = val;
            for(r; r < freetime.size(); r++){
                val = val + freetime[r] - freetime[l];
                l++;
                maxVal = max(maxVal, val);
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