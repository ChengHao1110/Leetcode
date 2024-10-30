#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<queue>

using namespace std;

class CMP{
public:
    bool operator() (string s1, string s2){
        return s1 + s2 < s2 + s1; 
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 1) return to_string(nums[0]);
        priority_queue<string, vector<string>, CMP> pq;
        for(int n : nums) pq.push(to_string(n));
        string ans = "";
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        string::iterator iter = ans.begin();
        while(iter != ans.end() && *iter == '0'){
            ans.erase(iter);
        }
        if(ans == "") return "0";
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
        int num;
        vector<int> arr;
        stringstream ss(input);
        while(ss >> num) arr.push_back(num);
        cout << sol.largestNumber(arr) << endl;
    }
    testcase.close();
    return 0;
}