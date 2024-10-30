#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), total = mean * (m + n);
        int curTotal = accumulate(rolls.begin(), rolls.end(), 0);
        int diff = total - curTotal;
        if(diff < n || diff > (n * 6)) return vector<int>();
        int remain = diff % n;
        vector<int> ans(n, diff / n);
        for(int i = 0; i < remain; i++) ans[i]++;
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
        int mean, n, num;
        ss >> mean >> n;
        getline(testcase, input);
        stringstream sss(input);
        vector<int> arr, ans;
        while(sss >> num) arr.push_back(num);
        ans = sol.missingRolls(arr, mean, n);
        for(int n : ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}