#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> table;
        for(auto &n : nums1) table.insert({n[0], n[1]});
        for(auto &n : nums2){
            if(table.find(n[0]) == table.end()){
                table.insert({n[0], n[1]});
            }
            else{
                table[n[0]] += n[1];
            }
        }
        vector<vector<int>> ans;
        for(auto &t : table){
            vector<int> a = {t.first, t.second};
            ans.push_back(a);
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