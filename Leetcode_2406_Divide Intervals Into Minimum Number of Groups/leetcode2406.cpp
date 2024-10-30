#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int groups = 1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        cout << "push: " << intervals[0][1] << endl;
        for(int i = 1; i < intervals.size(); i++){
            if(pq.top() < intervals[i][0]){
                cout << "pop: " << pq.top() << endl;
                pq.pop();
            }
            else{
                groups++;
            }
            pq.push(intervals[i][1]);
            cout << "push: " << intervals[i][1] << endl;
        }
        return groups;
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
        int s, e;
        stringstream ss(input);
        vector<vector<int>> intervals;
        while(ss >> s >> e){
            intervals.push_back(vector<int>{s, e});
        }
        cout << sol.minGroups(intervals) << endl;
    }
    testcase.close();
    return 0;
}