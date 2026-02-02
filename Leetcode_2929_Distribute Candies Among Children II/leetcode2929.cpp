#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(n > 3 * limit) return 0;
        long long ans = 0;
        for(int i = min(limit, n); i >= 0; i--){
            int remain = n - i;
            if(remain > 2 * limit) break;
            if(remain < limit){
                ans += (long long)(remain + 1);
            }
            else{
                int diff = remain - limit;
                ans += (long long)(limit - diff + 1);
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