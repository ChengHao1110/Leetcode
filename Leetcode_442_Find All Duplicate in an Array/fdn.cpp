#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(auto n : nums){
            map[n]++;
            if(map[n] > 1) ans.push_back(n);
        }
        return ans;
    }

    vector<int> findDuplicates_other(vector<int>& nums) {
        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
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
        vector<int> arr, ans;
        while(ss >> num){
            arr.push_back(stoi(num));
        }
        ans = sol.findDuplicates(arr);
        for(int n : ans) cout << n << " "; cout << endl;
    }

    return 0;
}