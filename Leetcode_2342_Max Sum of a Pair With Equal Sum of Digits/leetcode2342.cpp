#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxVal = -1;
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            int digitSum = 0, n = nums[i];
            while(n > 0){
                digitSum += (n % 10);
                n /= 10;
            }
            if(table.find(digitSum) == table.end()){
                table.insert({digitSum, nums[i]});
            }
            else{
                int val = nums[i] + table[digitSum];
                maxVal = max(maxVal, val);
                table[digitSum] = max(table[digitSum], nums[i]);
            }
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