#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(nums[i]) == table.end()){
                table.insert({nums[i], vector<int>{i}});
            }
            else{
                table[nums[i]].push_back(i);
            }
        }

        int ans = 0;
        for(auto idx = table.begin(); idx != table.end(); idx++){
            for(int i = 0; i < idx->second.size(); i++){
                for(int j = i + 1; j < idx->second.size(); j++){
                    if(idx->second[i] * idx->second[j] % k == 0) ans++;
                }
            }
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