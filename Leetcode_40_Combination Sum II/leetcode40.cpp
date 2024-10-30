#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int>::iterator iter = candidates.begin();
        while(iter != candidates.end()){
            if(*iter <= target) iter++;
            else candidates.erase(iter);
        }

        vector<int> possibleAns;  
        FindCombination(0, target, candidates, possibleAns, ans);

        return ans;
    }

    void FindCombination(int idx, int target, vector<int> cand, vector<int> pos_ans, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(pos_ans);
            return;
        }

        for(int i = idx; i < cand.size(); i++){
            if(i > idx && cand[i - 1] == cand[i]) continue;
            if(cand[i] <= target){
                pos_ans.push_back(cand[i]);
                FindCombination(i + 1, target - cand[i], cand, pos_ans, ans);
                pos_ans.pop_back();
            }
            else {
                break;
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
        stringstream ss(input);
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        arr.pop_back();
        vector<vector<int>> ans = sol.combinationSum2(arr, num);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    testcase.close();
    return 0;
}