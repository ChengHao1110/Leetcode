#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1] - nums[0]; // diff
        while(left < right){
            int mid = (left + right) / 2;
            if(IsSmallThanKPairs(nums, k, mid)){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }

    bool IsSmallThanKPairs(vector<int> nums, int k, int mid){
        int l = 0; //idx
        int count = 0;
        for(int r = 1; r < nums.size(); r++){
            while(nums[r] - nums[l] > mid) l++;
            count += r - l;
        }
        return (count < k);
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
        arr.pop_back();
        cout << sol.smallestDistancePair(arr, num) << endl;
    }
    testcase.close();
    return 0;
}