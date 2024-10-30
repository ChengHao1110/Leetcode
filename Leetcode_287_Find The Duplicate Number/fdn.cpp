#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Floyd Cycle Detection Algorithm
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    int findDuplicate_hashmap(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto n : nums){
            map[n]++;
            if(map[n] > 1) return n;
        }
        return 0;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string data;
    Solution sol;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        vector<int> arr;
        while(ss >> num){
            arr.push_back(stoi(num));
        }
        cout << sol.findDuplicate(arr) << endl;
        //cout << sol.findDuplicate_hashmap(arr) << endl;
    }

    return 0;
}