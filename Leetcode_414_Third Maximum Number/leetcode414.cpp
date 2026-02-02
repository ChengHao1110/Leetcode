#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> visited;
        int cur = nums[0];
        visited.insert(cur);

        for(int i = 1; i < nums.size(); i++){
            if(visited.size() == 3) return cur;
            else{
                if(!visited.count(nums[i])){
                    cur = nums[i];
                    visited.insert(cur);
                }
            }
        }
        return INT_MIN;
        /*
        int firstMax = INT_MIN ,secondMax = INT_MIN, thirdMax = INT_MIN;
        for(int n : nums){
            if(n < thirdMax) continue;

            if(n > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = n;
            }
            else if(n > secondMax){
                thirdMax = secondMax;
                secondMax = n;
            }
            else if(n > thirdMax){
                thirdMax = n;
            }
        }

        return thirdMax;
        */
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