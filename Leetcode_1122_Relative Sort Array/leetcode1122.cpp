#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> table;
        for(int i = 0; i < arr1.size(); i++){
            if(table.find(arr1[i]) != table.end()) table[arr1[i]]++;
            else table.insert({arr1[i], 1});
        }
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < table[arr2[i]]; j++){
                ans.emplace_back(arr2[i]);
            }
            table.erase(arr2[i]);
        }
        for(map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++){
            for(int j = 0; j < iter->second; j++){
                ans.emplace_back(iter->first);
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