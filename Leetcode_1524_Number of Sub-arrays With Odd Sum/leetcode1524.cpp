#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int m = 10e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int oddCnt = 0, evenCnt = 0;
        long long prefixSum = arr[0];
        int ans = 0;
        if(prefixSum % 2 == 1){
            ans = 1;
            oddCnt = 1;
        }
        else{
            evenCnt = 1;
        }
        
        for(int i = 1; i < arr.size(); i++){
            prefixSum += arr[i];
            if(prefixSum % 2 == 1){
                ans = (ans + 1 + evenCnt) % m;
                oddCnt++;
            }
            else{
                ans = (ans + oddCnt) % m;
                evenCnt++;
            }
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