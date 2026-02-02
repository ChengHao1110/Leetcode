#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0, s = 0;
        double sq = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                s = i * i + j * j;
                sq = sqrt(s);
                if(sq <= n && sq == (int)sq) ans++;
            }
        }

        return ans * 2;
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