#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int oil = 0, size = gas.size(), sumGas = 0, sumCost = 0;
        for(int i = 0; i < size; i++){
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if(sumGas < sumCost) return -1;

        int start = 0;
        for(int i = 0; i < size; i++){
            if(oil + gas[i] >= cost[i]){
                oil += (gas[i] - cost[i]);
            }
            else{
                start = i + 1;
                oil = 0;
            }
        }
        return start;
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
        int num;
        vector<int> gas, cost;
        while(ss >> num) gas.push_back(num);
        getline(testcase, input);
        stringstream sss(input);
        while(sss >> num) cost.push_back(num);
        cout << sol.canCompleteCircuit(gas, cost) << endl;
    }
    testcase.close();
    return 0;
}