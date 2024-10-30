#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size = chalk.size();
        vector<long long int> preSum(size, 0);
        long long int sum = 0;
        for(int i = 0; i < size; i++){
            sum += chalk[i];
            preSum[i] = sum;
        }
        if(k >= preSum[size - 1]) k = k % preSum[size - 1];
        int low = 0, high = size - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(preSum[mid] > k){
                high = mid - 1;
            }
            else if(preSum[mid] < k){
                low = mid + 1;
            }
            else{
                return mid + 1;
            }
        }
        return high + 1;
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
        stringstream ss(input);
        vector<int> arr;
        int num;
        while(ss >> num) arr.push_back(num);
        arr.pop_back();
        cout << sol.chalkReplacer(arr, num) << endl;
    }
    testcase.close();
    return 0;
}