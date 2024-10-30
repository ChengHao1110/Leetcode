#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //sliding window
        int left = 0, right = 0, count = 0, sum = 1;
        while(right < nums.size()){
            if(nums[right] < k){
                sum *= nums[right];
                if(sum < k){
                    count += right - left + 1;
                    right++;
                }
                else{
                    sum /= (nums[left] * nums[right]);
                    left++;
                }
            }
            else{
                right++;
                left = right;
                sum = 1;
            }
            //cout << "l: " << left << " r: " << right <<  " sum: " << sum <<  " count: " << count << endl;
        }
        return count;
    }

    int numSubarrayProductLessThanK_brute(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            long long int sum = 1;
            for(int j = i; j < nums.size(); j++){
                sum *= nums[j];
                if(sum < k) count++;
                else break;
            }
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

    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        vector<int> nums;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        int target = nums.back();
        nums.pop_back();
        Solution sol;
        cout << sol.numSubarrayProductLessThanK(nums, target) << endl;
        //cout << sol.numSubarrayProductLessThanK_brute(nums, target) << endl;
    }

    testcase.close();
    return 0;
}