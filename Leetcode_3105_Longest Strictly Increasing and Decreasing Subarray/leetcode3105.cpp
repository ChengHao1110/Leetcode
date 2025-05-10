#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int curI = nums[0], curD = nums[0], IncLen = 1, DecLen = 1, maxIncLen = 1, maxDecLen = 1;
        for(int i = 1; i < nums.size(); i++){
            //inc
            if(nums[i] > nums[i - 1]){
                IncLen++;
                if(maxIncLen < IncLen) maxIncLen = IncLen;
            }
            else{
                IncLen = 1;
            }
            //dec
            if(nums[i] < nums[i - 1]){
                DecLen++;
                if(maxDecLen < DecLen) maxDecLen = DecLen;
            }
            else{
                DecLen = 1;
            }
        }
        if(maxIncLen > maxDecLen) return maxIncLen;
        return maxDecLen;
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
        cout << sol.longestMonotonicSubarray(arr) << endl;
    }
    testcase.close();
    return 0;
}