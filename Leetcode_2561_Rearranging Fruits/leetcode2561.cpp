#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans = 0;
        int length = basket1.size(), minVal = INT_MAX;
        unordered_map<int, int> total, b1;
        for(int i = 0; i < length; i++){
            total[basket1[i]]++;
            b1[basket1[i]]++;
            total[basket2[i]]++;
            minVal = min(minVal, min(basket1[i], basket2[i]));
        }

        vector<int> swap;
        for(auto [fruit, cnt] : total){
            if(cnt % 2 == 1) return -1;
            int diff = b1[fruit] - (cnt / 2);
            for(int i = 0; i < abs(diff); i++){
                swap.push_back(fruit);
            }
        }
        
        sort(swap.begin(), swap.end());
        int swapTimes = swap.size() / 2;
        for(int i = 0; i < swapTimes; i++){
            ans += min(swap[i], 2 * minVal);
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

    }
    testcase.close();
    return 0;
}