#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int>> range;
        int maxFreq = 1;
        freq.insert({nums[0], 1});
        range.insert({nums[0], {0, 0}});
        for(int i = 1; i < nums.size(); i++){
            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]]++;
                range[nums[i]].second = i;
                if(maxFreq < freq[nums[i]]) maxFreq = freq[nums[i]];
            }
            else{
                freq.insert({nums[i], 1});
                range.insert({nums[i], {i, 0}});
            }
        }

        int ans = INT_MAX;
        if(maxFreq == 1) return 1;
        else{
            for(unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++){
                if(iter->second == maxFreq){
                    if(range[iter->first].second - range[iter->first].first < ans) ans = range[iter->first].second - range[iter->first].first;
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