#include<iostream>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    // leetcode
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // <value, idx> 
        // add to hash table
        int idx = 0;
        for(auto iter = nums.begin(); iter != nums.end(); iter++){
            map[*iter] = idx;
            idx++;
        }
        
        //find
        int idx1 = 0, idx2 = 0;
        vector<int> idxList;
        for(auto n = nums.begin(); n != nums.end(); n++){
            idx1 = n - nums.begin();
            int remain = target - *n;
            if(map.find(remain) != map.end()){
                if(map[remain] != idx1){
                    idx2 = map[remain];
                    idxList.push_back(idx1);
                    idxList.push_back(idx2);
                    break;
                }
            }
        }

        //return
        return idxList;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    vector<int> nums;
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        int target = nums.back();
        nums.pop_back(); 
        for(auto iter = nums.begin(); iter != nums.end(); iter++) cout << *iter << " ";
        cout << "[" << target << "]" << endl;
        Solution sol;
        vector<int> ans = sol.twoSum(nums, target);
        cout << "ans: ";
        for(auto iter = ans.begin(); iter != ans.end(); iter++) cout << *iter << " ";
        cout << endl << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}