#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int continuousOdd = 0, continuousEven = 0, evenOdd = 1;
        bool lastEven;
        if(nums[0] % 2 == 0){
            continuousEven = 1;
            lastEven = true;
        }
        else{
            continuousOdd = 1;
            lastEven = false;
        }

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                continuousEven++;
                if(!lastEven){
                    evenOdd++;
                    lastEven = !lastEven;
                }
            }
            else{
                continuousOdd++;
                if(lastEven){
                    evenOdd++;
                    lastEven = !lastEven;
                }
            }
        }

        return max(continuousEven, max(continuousOdd, evenOdd));
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