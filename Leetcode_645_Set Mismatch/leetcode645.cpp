#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> table;
        vector<int> ans(2, 0);
        for(int n : nums){
            if(table.find(n) == table.end()){
                table.insert({n, 1});
            }
            else{
                table[n]++;
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            if(table.find(i) != table.end()){
                if(table[i] > 1) ans[0] = i;
            } 
            else{
                ans[1] = i;
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
        stringstream ss(input);
        int num;
        vector<int> arr, ans;
        while(ss >> num) arr.push_back(num);
        ans = sol.findErrorNums(arr);
        cout << ans[0] << " " << ans[1] << endl << endl;
    }
    testcase.close();
    return 0;
}