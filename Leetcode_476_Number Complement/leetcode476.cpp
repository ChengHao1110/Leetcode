#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<deque>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        deque<int> comp;
        while(num > 0){
            comp.push_front(num & 1);
            num = num >> 1;
        }
        int sum = 0, base = 1;
        for(int i = comp.size() - 1; i >= 0; i--){
            sum += base * (!comp[i]);
            base *= 2;
        }
        return sum;
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
        ss >> num;
        cout << sol.findComplement(num) << endl;
    }
    testcase.close();
    return 0;
}