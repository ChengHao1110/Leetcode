#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool findOne = false;
        int n = nums.size(), minLen = INT_MAX, cntOne = 0;
        for(int n : nums){
            if(n == 1){
                findOne = true;
                cntOne++;
            }
        }
        if(findOne) return n - cntOne;
        
        for(int i = 0; i < n; i++){
            int len = -1, cur = nums[i];
            for(int j = i + 1; j < n; j++){
                cur = gcd(cur, nums[j]);
                if(cur == 1){
                    len = j - i;
                    break;
                }
            }
            if(len != -1) minLen = min(minLen, len);
        }

        if(minLen == INT_MAX) return -1;
        else return minLen + n - 1;
    }

    int gcd(int n1, int n2){
        int a = n1, b = n2, tmp;
        if(n1 < n2){
            a = n2;
            b = n1;
        }

        while(b > 0){
            tmp = a % b;
            a = b;
            b = tmp;
        }

        return a;
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