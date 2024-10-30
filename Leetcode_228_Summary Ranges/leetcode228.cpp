#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int left = 0, right = 0;
        while(right < nums.size() - 1){
            if((long long)nums[right + 1] - (long long)nums[right] == 1) right++;
            else{
                if(left == right){
                    ans.push_back(to_string(nums[left]));
                }
                else{
                    ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
                right++;
                left = right;
            }
        }
        if(left == right){
            ans.push_back(to_string(nums[left]));
        }
        else{
            ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }
        return ans;
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
        vector<int> arr;
        int num;
        stringstream ss(input);
        while(ss >> num) arr.push_back(num);
        vector<string> ans = sol.summaryRanges(arr);
        for(string s : ans) cout << s << endl;
    }
    testcase.close();
    return 0;
}