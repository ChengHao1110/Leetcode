#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[2] + nums[0] > nums[1]){
            set<int> s;
            s.insert(nums[0]);
            s.insert(nums[1]);
            s.insert(nums[2]);
            if(s.size() == 1) return "equilateral";
            else if(s.size() == 2) return "isosceles";
            else return "scalene";
        }
        return "none";
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