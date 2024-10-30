#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = INT_MIN;
        vector<bool> ans;
        for(int c : candies) if(c > maxNum) maxNum = c;
        for(int c : candies){
            if(c + extraCandies >= maxNum) ans.push_back(true);
            else ans.push_back(false);
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
        vector<bool> ans = sol.kidsWithCandies(nums, target);
        for(bool b : ans) cout << b << " "; cout << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}