#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        vector<string> ans(score.size(), "");
        int count = 1;
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            if(count > 3){
                ans[cur.second] = to_string(count);
            }
            else if(count == 1){
                ans[cur.second] = "Gold Medal";
            }
            else if(count == 2){
                ans[cur.second] = "Silver Medal";
            }
            else{
                ans[cur.second] = "Bronze Medal";
            }
            count++;
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