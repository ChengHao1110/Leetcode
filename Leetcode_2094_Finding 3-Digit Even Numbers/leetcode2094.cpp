#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digFreq(10, 0);
        for(int n : digits) digFreq[n]++;
        vector<int> ans;
        for(int i = 100; i < 1000; i += 2){
            unordered_map<int, int> numDigits;
            int num = i;
            while(num > 0){
                int d = num % 10;
                numDigits[d]++;
                num /= 10;
            }
            bool isAns = true;
            for(auto dig : numDigits){
                if(dig.second > digFreq[dig.first]){
                    isAns = false;
                    break;
                }
            }
            if(isAns) ans.push_back(i);
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