#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxVal = nums[0], sum = nums[0], l = 0, r = 1;
        unordered_map<int, int> table;
        table[nums[0]]++;

        while(r < nums.size()){
            table[nums[r]]++;
            if(table[nums[r]] == 1){
                sum += nums[r];
            }
            else{
                while(nums[l] != nums[r]){
                    sum -= nums[l];
                    table[nums[l]]--;
                    l++;
                }
                table[nums[l]]--;
                l++;
            }

            maxVal = max(maxVal, sum);
            r++;
        }

        return maxVal;
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