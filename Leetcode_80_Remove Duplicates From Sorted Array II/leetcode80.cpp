#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = nums[0], times = 1, idx = 0, i = 1;
        while(i < nums.size()){
            while(i < nums.size() && cur == nums[i]){
                i++;
                times++;
            }
            if(times > 2) times = 2;
            while(times--){
                nums[idx] = cur;
                idx++;
            }
            if(i < nums.size()){
                cur = nums[i];
                times = 1;
                i++;
            }
        }
        if(times > 0){
            while(times--){
                cout << idx << " ";
                nums[idx] = cur;
                idx++;
            }
        }
        
        //for(int i = 0; i < nums.size(); i++) cout << nums[i] << " "; cout << endl;
        return idx;
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