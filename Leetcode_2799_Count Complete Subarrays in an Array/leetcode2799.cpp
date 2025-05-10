#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(int n : nums) s.insert(n);
        int total = s.size(), l = 0, r = 0;
        unordered_map<int, int> table;
        int ans = 0;
        while(r < nums.size()){
            table[nums[r]]++;
            while(table.size() == total){
                ans += nums.size() - r;
                table[nums[l]]--;
                if(table[nums[l]] == 0) table.erase(nums[l]);
                l++;
            }
            r++;
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

    }
    testcase.close();
    return 0;
}