#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0, last = 0;
        while(nums[i] != 1){
            i++;
        }
        last = i;
        i++;
        while(i < nums.size()){
            if(nums[i] == 1){
                if(i - last - 1 < k) return false;
                last = i;
            }
            i++;
        }
        return true;
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