#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int base = 1, times = 0, ans = 0, cur = base;
        for(int i = 1; i <= n; i++){
            ans += cur;
            times++;
            cur++;
            if(times == 7){
                times = 0;
                base++;
                cur = base;
            }
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