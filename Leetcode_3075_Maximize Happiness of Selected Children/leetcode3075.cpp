#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, select = 0;
        int idx = happiness.size() - 1;
        sort(happiness.begin(), happiness.end());
        while(k--){
            if(happiness[idx] - select > 0){
                ans += (happiness[idx] - select);
                select++;
                idx--;
            }
            else break;
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