#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, times = 0;

        unordered_map<long long, long long> table;
        while(i < nums.size()){
            if(nums[i] == 0) times++;
            else if(times > 0){
                table[times]++;
                times = 0;
            }
            i++;
        }
        if(times > 0) table[times]++;

        long long ans = 0;
        for(auto t : table){
            ans += t.first * (t.first + 1) * t.second / 2;
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