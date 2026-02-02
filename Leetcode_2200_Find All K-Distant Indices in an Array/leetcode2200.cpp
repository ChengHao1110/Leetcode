#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keys;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key) keys.push_back(i);
        }

        vector<int> ans;
        int keyIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == keys[keyIdx]){
                ans.push_back(i);
                keyIdx++;
                if(keyIdx == keys.size()) break;
            }
            else{
                if(keys[keyIdx] - i <= k){
                    ans.push_back(i);
                }
                else if(keyIdx - 1 > 0 && i - keys[keyIdx - 1] <= k){
                    ans.push_back(i);
                }
            }
        }
        for(int i = 1; i <= k; i++){
            ans.push_back(keys[keys.size() - 1] + i);
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