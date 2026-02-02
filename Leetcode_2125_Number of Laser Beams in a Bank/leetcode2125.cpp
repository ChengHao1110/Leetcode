#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cur = 0, ans = 0;
        for(int i = 0; i < bank.size(); i++){
            int cnt = 0;
            for(int j = 0; j < bank[i].length(); j++){
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0){
                if(cur != 0) ans += cur * cnt;
                cur = cnt;
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