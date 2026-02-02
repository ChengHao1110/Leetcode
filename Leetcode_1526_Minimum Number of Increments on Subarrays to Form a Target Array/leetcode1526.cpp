#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        target.push_back(0);
        int cur = target[0], ans = 0;
        for(int i = 1; i < target.size(); i++){
            if(target[i] < cur){
                ans += cur - target[i];
            }
            cur = target[i];
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