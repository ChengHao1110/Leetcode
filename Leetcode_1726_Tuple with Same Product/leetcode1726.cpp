#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int i = 0;i < nums.size(); i++){
            for(int j = i + 1;j < nums.size(); j++){
                int val = nums[i] * nums[j];
                if(table.find(val) == table.end()){
                    table.insert({val, 1});    
                }
                else{
                    table[val]++;
                }
            }
        }
        int sum = 0;
        for(unordered_map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++){
            if(iter->second > 1){
                sum += (iter->second * (iter->second - 1)) / 2 * 8;
            }
        }
        return sum;
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
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        cout << sol.tupleSameProduct(arr) << endl;
    }
    testcase.close();
    return 0;
}