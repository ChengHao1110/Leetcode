#include<iostream>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        for(auto number: nums){
            if(table.find(number) == table.end()){
                table[number] = 1;
            }
            else{
                table[number]++;
            }
        }
        
        //for(auto t: table) cout << t.first << " " << t.second << endl;
        int maxFreq = INT_MIN, number = 0;
        for(auto t: table){
            if(t.second > maxFreq){
                maxFreq = t.second;
                number = t.first;
            }
        }
        return number;
    }

    int majorityElement_other(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
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
        Solution sol;
        cout << sol.majorityElement(nums) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}