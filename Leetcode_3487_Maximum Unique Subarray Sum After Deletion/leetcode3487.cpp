#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] <= 0) return nums[0];
        unordered_set<int> s;
        int sum = 0;
        for(int n : nums){
            if(n <= 0) break;
            if(s.find(n) == s.end()){
                sum += n;
                s.insert(n);
            }
        }
        return sum;
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