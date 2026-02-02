#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, small, equal, large;
        for(int n : nums){
            if(n < pivot) small.push_back(n);
            else if(n == pivot) equal.push_back(n);
            else large.push_back(n);
        }

        for(int n : small) ans.push_back(n);
        for(int n : equal) ans.push_back(n);
        for(int n : large) ans.push_back(n);

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