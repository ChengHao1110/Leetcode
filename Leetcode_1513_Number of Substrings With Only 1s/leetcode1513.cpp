#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        unordered_map<long long, long long> table;
        long long m = 1000000007, ans = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                cnt++;
            }
            else{
                if(cnt > 0) table[cnt]++;
                cnt = 0;
            }
        }

        if(cnt > 0) table[cnt]++;

        for(auto t : table){
            ans += (t.first * (t.first + 1) * t.second / 2) % m;
        }

        return (int)ans;
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