#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int minVal = 100000, maxVal = 1, border = 100000;
        vector<int> freq(border + 1, 0), diffArr(border + 1, 0);
        for(int x : nums){
            int left = max(1, x - k), right = min(border, x + k + 1);
            freq[x]++;
            diffArr[left]++;
            diffArr[right]--;
            minVal = min(minVal, left);
            maxVal = max(maxVal, right);
        }

        int ans = 0, cnt = 0;
        for(int i = minVal; i <= maxVal; i++){
            cnt += diffArr[i];
            ans = max(ans, freq[i] + min(cnt - freq[i], numOperations));
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