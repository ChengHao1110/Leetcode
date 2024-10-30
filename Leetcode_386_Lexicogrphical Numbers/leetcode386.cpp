#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i < 10; i++){
            if(i <= n){
                dfs(i, n, ans);
            }
        }
        return ans;
    }

    void dfs(int val, int target, vector<int> &ans){
        if(val > target) return;
        else{
            ans.push_back(val);
            for(int i = 0; i < 10; i++){
                dfs(val * 10 + i, target, ans);
            }
        }
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
        vector<int> ans = sol.lexicalOrder(stoi(input));
        for(int n : ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}