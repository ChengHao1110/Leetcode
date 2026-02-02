#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> topFreq(7, 0), botFreq(7, 0), sameFreq(7, 0);
        for(int i = 0; i < tops.size(); i++){
            topFreq[tops[i]]++;
            botFreq[bottoms[i]]++;
            if(tops[i] == bottoms[i]) sameFreq[tops[i]]++;
        }

        int minSwap = INT_MAX;
        for(int i = 1; i < 7; i++){
            if(topFreq[i] + botFreq[i] - sameFreq[i] < tops.size()) continue;
            minSwap = min(minSwap, min(topFreq[i], botFreq[i]) - sameFreq[i]);
        }
        if(minSwap == INT_MAX) return -1;
        return minSwap;
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