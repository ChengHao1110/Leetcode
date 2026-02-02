#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix[i] = sum + nums[i];
            sum += nums[i];
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(abs(prefix[i] - (sum - prefix[i])) % 2 == 0) ans++;
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