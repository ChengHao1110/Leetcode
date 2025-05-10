#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long prefix = 0;
        int ans = 0;
        for(int n : nums) prefix += n;
        if(prefix == 0) return 0;
        for(int i = 0; i < queries.size(); i++){
            ans++;
            for(int j = queries[i][0]; j <= queries[i][1]; j++){
                if(nums[j] >= queries[i][2]){
                    nums[j] -= queries[i][2];
                    prefix -= queries[i][2];
                }
                else{
                    prefix -= nums[j];
                    nums[j] = 0;
                }
            }
            if(prefix == 0) return ans;
        }
        return -1;
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