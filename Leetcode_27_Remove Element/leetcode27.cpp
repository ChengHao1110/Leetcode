#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iter = nums.begin();
        while(iter != nums.end()){
            if(*iter == val){
                nums.erase(iter);
            }
            else{
                iter++;
            }
        }
        //for(int i = 0; i < nums.size(); i++) cout << nums[i] << " "; cout << endl;
        return nums.size();
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
        vector<int> arr;
        int num;
        while(ss >> num) arr.push_back(num);
        int val = arr[arr.size() - 1];
        arr.pop_back();
        cout << sol.removeElement(arr, val) << endl;
    }
    testcase.close();
    return 0;
}