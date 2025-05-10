#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++) pq.push({nums[i], i});

        vector<bool> used(nums.size(), false);
        long long sum = 0;
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            if(!used[cur.second]){
                sum += cur.first;
                used[cur.second] = true;
                if(cur.second - 1 >= 0) used[cur.second - 1] = true;
                if(cur.second + 1 < nums.size()) used[cur.second + 1] = true;
            }
        }

        return sum;
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