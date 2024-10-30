#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l = 0, r = 0, badIdx = 0;
        int maxIdx = -1, minIdx = -1;
        long long int count = 0; 
        while( r < nums.size()){
            if(nums[r] <= maxK && nums[r] >= minK){
                if(nums[r] == minK){
                    minIdx = r;
                }
                if(nums[r] == maxK){
                    maxIdx = r;
                }
                count += max(min(maxIdx, minIdx) - l + 1, 0);
            }
            else{
                l = r + 1;
            }
            r++;
        }
        return count;
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
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        int maxK = nums.back();
        nums.pop_back();
        int minK = nums.back();
        nums.pop_back(); 
        Solution sol;
        //cout << "count: " << sol.subarraysWithKDistinct_ver1(nums, target) << endl;
        cout << "count: " << sol.countSubarrays(nums, minK, maxK) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}