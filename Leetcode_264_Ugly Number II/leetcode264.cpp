#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> existed;
        vector<long long> ugly = {2, 3, 5};
        pq.push(1);
        long long num, in;
        for(int i = 0; i < n; i++){
            num = pq.top();
            for(int j = 0; j < 3; j++){
                in = num * ugly[j];
                if(existed.count(in) == 0){
                    pq.push(in);
                    existed.insert(in);
                }
            }
            pq.pop();
        }
        return num;
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
        stringstream ss(input);
        int num;
        ss >> num;
        cout << sol.nthUglyNumber(num) << endl;
    }
    testcase.close();
    return 0;
}