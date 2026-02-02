#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> lake;
        set<int> dry;
        for(int i = 0; i < rains.size(); i++){
            if(rains[i] == 0) dry.insert(i);
            else{
                int id = rains[i];
                if(lake.find(id) != lake.end()){
                    int deadline = lake[id];
                    auto it = dry.lower_bound(deadline);
                    if(it == dry.end()) return {};
                    ans[*it] = id;
                    dry.erase(it);
                }
                lake[id] = i;
                ans[i] = -1;
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