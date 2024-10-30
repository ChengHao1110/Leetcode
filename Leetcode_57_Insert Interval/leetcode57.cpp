#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return vector<vector<int>> (1, newInterval);
        int low = 0, high = intervals.size() - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(newInterval[0] == intervals[mid][0]){
                high = mid;
                break;
            }
            else if(newInterval[0] > intervals[mid][0]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        intervals.insert(intervals.begin() + high + 1, newInterval);
        //merge
        vector<vector<int>> ans;
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= e){
                if(intervals[i][1] > e) e = intervals[i][1];
            }
            else{
                ans.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.push_back({s, e});
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
        stringstream ss(input);
        int s, e;
        vector<vector<int>> intervals;
        while(ss >> s >> e){
            intervals.push_back({s, e});
        }
        intervals.pop_back();
        vector<int> newInterval = {s,e};
        vector<vector<int>> ans = sol.insert(intervals, newInterval);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i][0] <<"," << ans[i][1] << endl;
        }
    }
    testcase.close();
    return 0;
}