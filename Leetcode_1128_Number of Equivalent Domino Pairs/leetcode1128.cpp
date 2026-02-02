#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> table;
        for(int i = 0; i < dominoes.size(); i++){
            string key = to_string(dominoes[i][0]) + to_string(dominoes[i][1]), revKey = to_string(dominoes[i][1]) + to_string(dominoes[i][0]);
            if(table.find(key) != table.end()){
                table[key]++;
            }
            else if(table.find(revKey) != table.end()){
                table[revKey]++;
            }
            else{
                table[key]++;
            }
        }

        int ans = 0;
        for(auto t : table){
            ans += (t.second * (t.second - 1)) / 2;
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