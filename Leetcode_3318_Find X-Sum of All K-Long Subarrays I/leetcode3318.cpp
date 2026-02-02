#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), i = 0;
        vector<int> ans;
        unordered_map<int, int> table;
        for(i; i < k; i++){
            table[nums[i]]++;
        }
        for(i; i < n; i++){
            ans.push_back(GetResult(table, x));
            table[nums[i - k]]--;
            table[nums[i]]++;
        }
        ans.push_back(GetResult(table, x));
        return ans;
    }

    int GetResult(unordered_map<int, int> table, int x){
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto [key, val] : table){
            pq.push({val, key});
        }
        int res = 0;
        if(pq.size() >= x){
            for(int i = 0; i < x; i++){
                auto [freq, val] = pq.top();
                pq.pop();
                res += freq * val;
            }
        }
        else{
            while(!pq.empty()){
                auto [freq, val] = pq.top();
                pq.pop();
                res += freq * val;
            }
        }

        return res;
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