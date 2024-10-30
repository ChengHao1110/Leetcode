#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low, high, mid;
        for(int i = 0; i < numbers.size() - 1; i++){
            int remain = target - numbers[i];
            low = i + 1;
            high = numbers.size() - 1;
            while(low <= high){
                mid = (low + high) / 2;
                if(remain == numbers[mid]) return vector<int>{i + 1, mid + 1};
                else if(remain < numbers[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return vector<int>{-1, -1};
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