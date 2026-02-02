#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = 0, n = 1, zeroIdx = -1;
        vector<int> prefix(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroCnt++;
                zeroIdx = i;
                if(zeroCnt == 2) break;
                continue;
            }

            n *= nums[i];
            prefix[i] = n;
        }

        vector<int> ans(nums.size(), 0);
        if(zeroCnt > 1) return ans;
        if(zeroCnt == 1){
            ans[zeroIdx] = n;
            return ans;
        }
        for(int i = 0; i < nums.size(); i++){
            ans[i] = n / nums[i];
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