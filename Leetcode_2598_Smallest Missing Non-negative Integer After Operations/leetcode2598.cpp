#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> table(value, 0);
        for(int i = 0;i < nums.size(); i++){
            int slot = nums[i] % value;
            if(nums[i] < 0) slot = ((nums[i] % value) + value) % value;
            table[slot]++;
        }

        int ans = 0, idx = 0, min = table[0];
        for(int i = 1; i < value; i++){
            if(table[i] < min){
                min = table[i];
                idx = i;
            }
        }

        ans = value * min + idx - 1;
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