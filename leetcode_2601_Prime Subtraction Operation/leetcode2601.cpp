#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxNum + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i <= sqrt(maxNum); i++){
            if(isPrime[i]){
                for(int j = 2; i * j <= maxNum; j++){
                    isPrime[i * j] = false;
                }
            }
        }

        int currValue = 0;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            
            if (difference < 0) {
                return false;
            }
            
            if (isPrime[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return true;
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