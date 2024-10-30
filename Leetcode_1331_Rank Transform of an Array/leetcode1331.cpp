#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return vector<int>();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < arr.size(); i++) pq.push({arr[i], i});
        vector<int> ans(arr.size(), 0);
        pair<int, int> curPair = pq.top();
        pq.pop();
        int curVal = curPair.first, rank = 1;
        ans[curPair.second] = rank;
        while(!pq.empty()){
            curPair = pq.top();
            pq.pop();
            if(curPair.first != curVal){
                curVal = curPair.first;
                rank++;
            }
            ans[curPair.second] = rank;
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