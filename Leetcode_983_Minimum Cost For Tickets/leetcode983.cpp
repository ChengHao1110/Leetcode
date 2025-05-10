#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    unordered_set<int> travelDay;
    int lastDay = 0;

    int solve(vector<int> &dp, const vector<int> days, const vector<int> costs, int curDay){
        if(curDay > lastDay) return 0;
        if(travelDay.find(curDay) == travelDay.end()) return solve(dp, days, costs, curDay + 1);
        if(dp[curDay] != -1) return dp[curDay];

        int buyOne = costs[0] + solve(dp, days, costs, curDay + 1);
        int buySeven = costs[1] + solve(dp, days, costs, curDay + 7);
        int buyThirty = costs[2] + solve(dp, days, costs, curDay + 30);

        dp[curDay] = min(buyOne, min(buySeven, buyThirty));
        return dp[curDay];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);
        for(int d : days) travelDay.insert(d);
        return solve(dp, days, costs, 1);
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