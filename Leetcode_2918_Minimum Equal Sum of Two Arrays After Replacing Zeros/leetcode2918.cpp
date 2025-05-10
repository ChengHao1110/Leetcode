#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long leftSum = 0, rightSum = 0;
        int leftZeros = 0, rightZeros = 0;
        for(int i = 0; i < nums1.size(); i++){
            leftSum += nums1[i];
            if(nums1[i] == 0) leftZeros++;
        }
        for(int i = 0; i < nums2.size(); i++){
            rightSum += nums2[i];
            if(nums2[i] == 0) rightZeros++;
        }
        if(leftZeros == 0 && rightZeros == 0){
            if(leftSum == rightSum) return leftSum;
            else return -1;
        }
        else if(leftZeros != 0 && rightZeros == 0){
            if(rightSum >= leftSum + leftZeros) return rightSum;
            else return -1;
        }
        else if(leftZeros == 0 && rightZeros != 0){
            if(rightSum + rightZeros <= leftSum) return leftSum;
            else return -1;
        }
        else{
            return max(rightSum + rightZeros, leftSum + leftZeros);
        }

        return -1;
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