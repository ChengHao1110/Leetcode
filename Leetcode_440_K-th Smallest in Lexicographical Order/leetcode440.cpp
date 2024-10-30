#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;  // Start from the first prefix (1)
        k--;  // Decrease k by 1 because we are starting from 1
        
        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                curr++;  // Move to the next sibling (prefix)
                k -= steps;
            } else {
                curr *= 10;  // Move to the first child
                k--;  // We have covered the current number
            }
        }
        
        return curr;
    }

    long countSteps(long curr, long n) {
        long steps = 0, first = curr, last = curr;
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber_DFS(int n, int k) {
        int ans;
        for(int i = 1; i < 10; i++){
            if(i <= n){
                dfs(i, n, ans, k);
            }
        }
        return ans;
    }

    void dfs(int val, int target, int &ans, int &k){
        if(0 == k) return;
        if(val > target) return;
        else{
            k--;
            if(k == 0){
                ans = val;
                return;
            }
            for(int i = 0; i < 10; i++){
                dfs(val * 10 + i, target, ans, k);
            }
        }
    }

    int findKthNumber_brute(int n, int k) {
        vector<string> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(to_string(i));
        }
        sort(nums.begin(), nums.end());
        return stoi(nums[k - 1]);
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        int n, k;
        ss >> n >> k;
        cout << sol.findKthNumber(n, k) << endl;
    }
    testcase.close();
    return 0;
}