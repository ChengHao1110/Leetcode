#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int ans = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    if(i + 2 < nums.size()){
                        nums[i] = 1;
                        nums[i + 1] = (nums[i + 1] == 0) ? 1 : 0;
                        nums[i + 2] = (nums[i + 2] == 0) ? 1 : 0;
                        ans++;
                    }
                    else{
                        return -1;
                    }
                }
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