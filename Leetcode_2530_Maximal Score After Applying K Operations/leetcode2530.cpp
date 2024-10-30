#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        for(int i = 0 ; i < k; i++){
            if(pq.empty()){
                return ans;
            }
            else{
                int val = pq.top(), newVal;
                ans += val;
                pq.pop();
                newVal = ceil(val / 3.0);
                if(newVal != 0) pq.push(newVal);
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