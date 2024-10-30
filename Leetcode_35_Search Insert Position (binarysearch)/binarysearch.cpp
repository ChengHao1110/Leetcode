#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

// leetcode 35. Search Insert Position

class Solution {
    int low, mid, high;
public:
    // leet code function
    int searchInsert(vector<int>& nums, int target) {
        low = 0;
        high = nums.size() - 1;
        while(true){
            mid = low + (high - low) / 2;
            // equal
            if(nums[mid] == target) return mid;
            // smaller than target
            if(nums[mid] < target) low = mid + 1;
            // larger than target
            if(nums[mid] > target) high = mid - 1;
            //return
            if(low > high) return low;
        }
    }

    // my function
    void insert(vector<int> nums,int target, int index){
        vector<int>::iterator iter;
        nums.insert(nums.begin() + index, target);
        for(iter = nums.begin(); iter != nums.end(); iter++) cout << *iter << " ";
        cout << endl;
    }

};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }
    vector<int> nums;
    int num;
    while(!testcase.eof()){
        testcase >> num;
        nums.push_back(num);
    }

    //print vector
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;

    Solution sol;
    int target = 0, index = 0;
    while(true){
        cout << "input target: ";
        cin >> target;
        index = sol.searchInsert(nums, target);
        cout << "insert index: " << index << endl;
        cout << "after insert: ";
        sol.insert(nums, target, index);
    }
    
    return 0;
}