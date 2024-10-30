#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, count = 0;
        while(numBottles){
            count += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty -= numBottles * numExchange;
        }
        return count;
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
        int b, e;
        ss >> b >> e;
        cout << sol.numWaterBottles(b, e) << endl;
    }
    testcase.close();
    return 0;
}