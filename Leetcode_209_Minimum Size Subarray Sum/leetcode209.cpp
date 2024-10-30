#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, dist = INT_MAX;
        while(right < nums.size()){
            sum += nums[right];
            if(sum >= target){
                while(left <= right && sum >= target){
                    sum -= nums[left];                    
                    left++;
                }
                dist = min(dist, right - left + 2);
            }
            right++;
        }
        if(dist == INT_MAX) return 0;
        return dist;
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
        cout << sol.minSubArrayLen(num, arr) << endl;
    }
    testcase.close();
    return 0;
}