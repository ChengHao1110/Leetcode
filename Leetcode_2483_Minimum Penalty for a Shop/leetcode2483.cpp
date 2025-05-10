#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> op(customers.length() + 1, 0), cl(customers.length() + 1, 0);
        int preOp = 0, preCl = 0;
        for(int i = 0; i < customers.length(); i++){
            preOp += (customers[i] == 'N') ? 1 : 0;
            preCl += (customers[i] == 'Y') ? 1 : 0;
            op[i + 1] = preOp;
            cl[i + 1] = preCl;
        }

        int min = INT_MAX, idx = 0;
        for(int i = 0; i < op.size(); i++){
            if(op[i] + cl[cl.size() - 1] - cl[i] < min){
                min = op[i] + cl[cl.size() - 1] - cl[i];
                idx = i;
            } 
        }

        return idx;
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