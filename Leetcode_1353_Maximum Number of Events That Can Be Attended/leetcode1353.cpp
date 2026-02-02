#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int n = events.size(), i = 0, day = 1, ans = 0;

        for(; i < n || !pq.empty(); day++){
            // current no event
            if(pq.empty()) day = events[i][0];

            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            while (!pq.empty() && pq.top()<day) 
                pq.pop();
                
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        
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

    }
    testcase.close();
    return 0;
}