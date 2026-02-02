#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int n : nums){
            table[n]++;
        }

        vector<pair<int, int>> v;
        for(auto t : table){
            v.push_back({t.first, t.second});
        }

        sort(v.begin(), v.end());
        int maxLen = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first - v[i - 1].first == 1){
                maxLen = max(maxLen, v[i].second + v[i - 1].second);
            }
        }

        return maxLen;
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