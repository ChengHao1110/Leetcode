#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() > 1){
            if(nums[0] > nums[1]) return 0;
            if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        }
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            if(nums[mid + 1] > nums[mid]){
                low = mid + 1;
            }
            else if(nums[mid - 1] > nums[mid]){
                high = mid - 1;
            }
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
        stringstream ss(input);
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        cout << sol.findPeakElement(arr) << endl;
    }
    testcase.close();
    return 0;
}