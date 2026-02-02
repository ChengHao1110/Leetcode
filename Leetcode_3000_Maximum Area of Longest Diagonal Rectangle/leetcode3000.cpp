#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1, maxArea = -1;
        for(auto d : dimensions){
            int val = d[0] * d[0] + d[1] * d[1];
            if(val > maxDiag){
                maxDiag = val;
                maxArea = d[0] * d[1];
            }
            else if(val == maxDiag){
                maxArea = max(maxArea, d[0] * d[1]);
            }
        }
        return maxArea;
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