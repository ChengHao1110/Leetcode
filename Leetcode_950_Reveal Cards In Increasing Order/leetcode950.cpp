#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size() <= 1) return deck;
        sort(deck.begin(), deck.end());
        vector<int> idx;
        for(int i = 0; i < deck.size(); i++) idx.push_back(i);

        // order
        for(int i = 0; i < deck.size() - 2; i++){
            idx.push_back(idx[i + 1]);
            idx.erase(idx.begin() + i + 1);
        }
        //for(int n : idx) cout << n << " "; cout << endl;

        // ans
        vector<int> ans(deck.size(), 0);
        for(int i = 0; i < idx.size(); i++) ans[idx[i]] = deck[i];
        return ans;
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
        vector<int> nums, ans;
        int num;
        while(ss >> num) nums.push_back(num);
        ans = sol.deckRevealedIncreasing(nums);
        for(int n : ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}