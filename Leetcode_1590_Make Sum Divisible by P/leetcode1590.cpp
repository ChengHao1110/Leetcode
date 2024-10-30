#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        int remain = sum % p;
        if(remain == 0) return 0;

        unordered_map<int, int> recIdx;
        recIdx[0] = -1;
        int minLen = nums.size();
        sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int curMod = sum % p;
            int targetMod = (curMod - remain + p) % p;
            if(recIdx.find(targetMod) != recIdx.end()){
                minLen = min(minLen, i - recIdx[targetMod]);
            }
            recIdx[curMod] = i;
        }

        if(minLen == nums.size()) return -1;
        else return minLen;
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