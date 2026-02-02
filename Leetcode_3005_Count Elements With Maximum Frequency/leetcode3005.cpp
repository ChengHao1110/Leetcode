#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> table;
        int maxFreq = -1, times = 0;
        for(int n : nums){
            table[n]++;
        }

        for(auto t : table){
            if(t.second > maxFreq){
                maxFreq = t.second;
                times = 1;
            }
            else if(t.second == maxFreq){
                times++;
            }
        }

        return maxFreq * times;
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