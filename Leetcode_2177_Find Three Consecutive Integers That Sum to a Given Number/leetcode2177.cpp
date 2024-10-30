#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num == 0) return vector<long long>{-1, 0, 1};
        bool neg = false;
        if(num < 0){
            num = -num;
            neg = true;
        }
        if((num - 3) % 3 != 0) return vector<long long>();
        long long start = (num - 3) / 3;
        if(neg) return vector<long long>{-start - 2, -start - 1, -start};
        else return vector<long long>{start, start + 1, start + 2};
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
        vector<long long> ans = sol.sumOfThree(num);
        for(long long ll : ans) cout << ll << " "; cout << endl;
    }
    testcase.close();
    return 0;
}