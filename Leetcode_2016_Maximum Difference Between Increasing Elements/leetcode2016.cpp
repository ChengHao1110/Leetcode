#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = nums[0], r = 1, ans = -1;
        while(r < nums.size()){
            if(nums[r] > min){
                ans = max(ans, nums[r] - min);
            }
            else{
                min = nums[r];
            }
            r++;
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