#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class CMP{
public:
    bool operator()(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    } 
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), CMP());
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= right){
                if(intervals[i][1] > right) right = intervals[i][1];
            } 
            else{
                ans.push_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back(vector<int>{left, right});
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
        int n1, n2;
        vector<vector<int>> intervals, ans;
        while(ss >> n1 >> n2){
            intervals.push_back(vector<int>{n1, n2});
        }
        ans = sol.merge(intervals);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i][0] << ", " << ans[i][1] << endl;
        }
    }
    testcase.close();
    return 0;
}