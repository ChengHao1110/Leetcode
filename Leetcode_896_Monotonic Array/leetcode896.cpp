#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;
        bool inc;
        int i = 1;
        while(i < nums.size()){
            if(nums[i] > nums[i - 1]){
                inc = true;
                break;
            }
            if(nums[i] < nums[i - 1]){
                inc = false;
                break;
            }
            i++;
        }
        if(i == nums.size()) return true;
        if(inc){
            for(i = 1; i < nums.size(); i++){
                if(nums[i] < nums[i - 1]) return false;
            }
        }
        else{
            for(i = 1; i < nums.size(); i++){
                if(nums[i] > nums[i - 1]) return false;
            }
        }
        return true;
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