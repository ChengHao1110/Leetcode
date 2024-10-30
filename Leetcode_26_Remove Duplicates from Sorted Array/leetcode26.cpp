#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        int count = 0, lastVal = *iter;
        iter++;
        while(iter != nums.end()){
            cout << "last: " << lastVal << " cur: " << *iter << endl;
            if(*iter == lastVal){
                nums.erase(iter);
                count++;
            }
            else{
                lastVal = *iter;
                iter++;
            }
        }
        //for(int i = 0; i < count; i++) nums.push_back(i);
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
        cout << sol.removeDuplicates(arr) << endl;
        for(int n : arr) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}