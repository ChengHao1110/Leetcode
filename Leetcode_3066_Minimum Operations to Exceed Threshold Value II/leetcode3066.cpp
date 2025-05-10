#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int n : nums) pq.push(n);
        int ans = 0;
        while(pq.size() > 1){
            long long n1, n2;
            n1 = pq.top();
            pq.pop();
            n2 = pq.top();
            pq.pop();
            if(n1 > k - 1 && n2 > k - 1){
                return ans;
            }
            else{
                ans++;
                pq.push(n1 * 2 + n2);
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