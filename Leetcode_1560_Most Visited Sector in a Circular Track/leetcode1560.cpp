#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> times(n + 1, 0);
        int cur = rounds[0], end;
        times[cur]++;
        
        for(int i = 1; i < rounds.size(); i++){
            end = rounds[i];
            while(cur != end){
                cur++;
                if(cur == n + 1) cur = 1;
                times[cur]++;
            }
        }

        int maxVal = 0;
        for(int i = 1; i < times.size(); i++){
            maxVal = max(maxVal, times[i]);
        }

        vector<int> ans;
        for(int i = 1; i < times.size(); i++){
            if(times[i] == maxVal) ans.push_back(i);
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