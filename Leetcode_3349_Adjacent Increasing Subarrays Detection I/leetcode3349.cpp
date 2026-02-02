#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i <= nums.size() - 2 * k; i++){
            int j = i + 1;
            bool inc = true;
            for(j; j < i + k; j++){
                if(nums[j] <= nums[j - 1]){
                    inc = false;
                    break;
                }
            }
            if(!inc) continue;
            j = i + k + 1;
            for(j; j < i + 2 * k; j++){
                if(nums[j] <= nums[j - 1]){
                    inc = false;
                    break;
                }
            }
            if(inc) return true;
            
        }
        return false;
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