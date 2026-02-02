#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, i = 0;
        for(i; i < nums.size(); i++){
            if(nums[i] < 0) neg++;
            else if(nums[i] == 0) continue;
            else break;
        }
        return max(neg, (int)nums.size() - i);
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