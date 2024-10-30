#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(i > cur) return false;
            cur = max(cur, i + nums[i]);
            if(cur >= nums.size() - 1) return true;
        }
        return false;
        /*
        //TLE
        vector<bool> pos(nums.size(), false);
        pos[0] = true;
        for(int i = 0 ; i < nums.size(); i++){
            if(pos[i]){
                int temp = i;
                while(nums[i]--){
                    if(++temp < nums.size()) pos[temp] = true;
                }
            }
            else{
                return false;
            }
        }
        return true;
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
        stringstream ss(input);
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        cout << sol.canJump(arr) << endl;
    }
    testcase.close();
    return 0;
}