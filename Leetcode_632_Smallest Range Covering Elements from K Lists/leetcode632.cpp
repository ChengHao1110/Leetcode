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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minRange = 0, curMax = INT_MIN, curMin = INT_MAX;
        vector<int> ans(2, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            curMax = max(curMax, nums[i][0]);
            pq.push(vector<int>{nums[i][0], i, 0});
        }
        curMin = pq.top()[0];
        minRange = curMax - curMin;
        ans[0] = curMin;
        ans[1] = curMax;
        while(1){
            vector<int> cur = pq.top();
            int listNum = cur[1], listIdx = cur[2];
            pq.pop();
            if(listIdx + 1 < nums[listNum].size()){
                pq.push(vector<int>{nums[listNum][listIdx + 1], listNum, listIdx + 1});
                curMax = max(curMax, nums[listNum][listIdx + 1]);
                curMin = pq.top()[0];
                if(curMax - curMin < minRange){
                    minRange = curMax - curMin;
                    ans[0] = curMin;
                    ans[1] = curMax;
                }
            }
            else{
                break;
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
        int time = stoi(input);
        vector<vector<int>> nums;
        for(int i = 0; i < time; i++){
            getline(testcase, input);
            stringstream ss(input);
            int num;
            vector<int> arr;
            while(ss >> num){
                arr.push_back(num);
            }
            nums.push_back(arr);
        }
        vector<int> ans = sol.smallestRange(nums);
        cout << ans[0] << " , " << ans[1] << endl;
    }
    testcase.close();
    return 0;
}