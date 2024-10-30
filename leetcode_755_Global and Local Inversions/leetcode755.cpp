#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= i + 1 && nums[i] >= i - 1) continue;
            else return false;
        }
        return true;
    }

    bool isIdealPermutation_ver2(vector<int>& nums) {
        //time limited
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                for(int j = i + 2; j < nums.size(); j++){
                    if(nums[i] > nums[j]) return false;
                }
            }
            else{
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] > nums[j]) return false;
                }
            }
        }
        return true;
    }

    bool isIdealPermutation_brute(vector<int>& nums) {
        int glo = 0, loc = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]) loc++;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] > nums[j]) glo++;
            }
        }
        cout << "global: " << glo << " local: " << loc << endl;
        return (glo == loc);
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }
    
    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> nums;
        int num;
        while(ss >> num) nums.push_back(num);
        if(sol.isIdealPermutation(nums)) cout << "T" << endl;
        else cout << "F" << endl;
    }
    testcase.close();
    return 0;
}