#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if(nums1.size() % 2 == 1 && nums2.size() % 2 == 1){
            for(int n : nums1) ans ^= n;
            for(int n : nums2) ans ^= n;
        }
        else if(nums1.size() % 2 == 0 && nums2.size() % 2 == 1){
            for(int n : nums1) ans ^= n;
        }
        else if(nums1.size() % 2 == 1 && nums2.size() % 2 == 0){
            for(int n : nums2) ans ^= n;
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