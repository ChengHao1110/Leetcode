#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long int> prefixSum;
        long long int sum = 0;
        prefixSum.push_back(sum);
        for(int n : differences){
            sum += n;
            prefixSum.push_back(sum);
        }
        sort(prefixSum.begin(), prefixSum.end());
        int ans = (upper - lower) - (prefixSum[prefixSum.size() - 1] - prefixSum[0]) + 1;
        if(ans >= 0) return ans;
        else return 0;
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