#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int dec = 0;
        if(nums[nums.size() - 1] > nums[0]) dec++;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                dec++;
                if(dec == 2) break;
            }
        }
        if(dec < 2) return true;
        else return false;
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
        if(sol.check(arr)) cout << "true" << endl;
        else cout << "false" << endl;
    }
    testcase.close();
    return 0;
}