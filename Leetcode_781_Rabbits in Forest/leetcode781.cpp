#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> table;
        int ans = 0, group;
        for(int n : answers){
            table[n]++;
        }
        for(auto t : table){
            group = (t.second % (t.first + 1) == 0) ? t.second / (t.first + 1) : (t.second / (t.first + 1)) + 1;
            ans += group * (t.first + 1);
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