#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(), maxVal = INT_MIN;
        vector<int> prefixSum(n, 0);
        for(int i = n - 1; i >= n - k; i--){
            prefixSum[i] = energy[i];
            maxVal = max(maxVal, prefixSum[i]);
        }
        for(int i = n - 1 - k; i >= 0; i--){
            prefixSum[i] = prefixSum[i + k] + energy[i];
            maxVal = max(maxVal, prefixSum[i]);
        }

        return maxVal;
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