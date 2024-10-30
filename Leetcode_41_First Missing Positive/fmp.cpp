#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //ignore negative value, 0, out of range (nums.size())
        int idx = 0;
        while(idx < nums.size()){
            if((nums[idx] > 0 && nums[idx] <= nums.size()) && (nums[idx] != idx + 1)){
                if(nums[idx] == nums[nums[idx] - 1]) idx++;
                else swap(nums, idx, nums[idx] - 1);
            }
            else{
                idx++;
            }
        }
        for(int n : nums) cout << n << " "; cout << endl;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }

    void swap(vector<int>& nums, int pos1, int pos2){
        int temp = nums[pos1];        
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string data;
    Solution sol;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        vector<int> arr;
        while(ss >> num){
            arr.push_back(stoi(num));
        }
        cout << sol.firstMissingPositive(arr) << endl;
    }
    return 0;
}