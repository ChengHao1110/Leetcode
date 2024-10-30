#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int l = 0, r = 0, maxLength = -1;
        while(r < nums.size()){
            map[nums[r]]++;
            if(map[nums[r]] > k){
                while(nums[l] != nums[r]){
                    map[nums[l]]--;
                    l++;
                }
                map[nums[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        
        return maxLength;
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
        int target = nums.back();
        nums.pop_back(); 
        Solution sol;
        cout << "length: " << sol.maxSubarrayLength(nums, target) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}