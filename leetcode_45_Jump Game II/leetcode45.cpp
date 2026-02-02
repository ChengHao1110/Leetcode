#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0, jump = 0;
        while(pos != nums.size() - 1){
            int steps = nums[pos];
            jump++;
            if(pos + steps >= nums.size() - 1) break;

            int maxForward = 0, maxPos;
            for(int i = pos + 1; i <= pos + steps; i++){
                if(i + nums[i] > maxForward){
                    maxForward = i + nums[i];
                    maxPos = i;
                }
            }
            pos = maxPos;
        }
        return jump;
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