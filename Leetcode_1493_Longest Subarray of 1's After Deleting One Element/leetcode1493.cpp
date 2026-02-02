#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros = 0, length = 0, maxLen = 0, l = 0, r = 0;
        while(r < nums.size()){
            if(nums[r] == 0 && zeros == 0){
                zeros++;
            }
            else if(nums[r] == 0 && zeros == 1){
                while(nums[l] != 0){
                    l++;
                    length--;
                }
                length--; //remove 0
                l++;
            }
            length++;

            maxLen = max(maxLen, length);
            r++;
        }

        return maxLen - 1;
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