#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> cand;
        int r = nums.size(), c = nums[0].size();
        for(int i = 0; i < r; i++){
            if(i != c - 1 - i){
                cand.push_back(nums[i][i]);
                cand.push_back(nums[i][c - 1 - i]);
            }
            else{
                cand.push_back(nums[i][i]);
            }
        }
        sort(cand.begin(), cand.end(), greater<int>());
        for(int i = 0; i < cand.size(); i++){
            bool isPrime = true;
            if(cand[i] == 1) break;
            for(int n = 2; n <= (int)sqrt(cand[i]); n++){
                if(cand[i] % n == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) return cand[i];
        }
        return 0;
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