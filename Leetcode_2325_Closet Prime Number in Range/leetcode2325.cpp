#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> num(right + 1, true);
        num[0] = num[1] = false;
        int idx = 2;
        while(idx * idx <= right){
            if(num[idx]){
                int k = idx * idx;
                while(k <= right){
                    num[k] = false;
                    k += idx;
                }
            }
            idx++;
        }
        vector<int> prime;
        for(int i = left; i < right + 1; i++){
            if(num[i]) prime.push_back(i);
        }
        
        if(prime.size() <= 1) return vector<int>{-1, -1};
        vector<int> ans = {prime[0], prime[1]};
        int min = prime[1] - prime[0];
        for(int i = 2; i < prime.size(); i++){
            if(prime[i] - prime[i - 1] < min){
                min = prime[i] - prime[i - 1];
                ans[0] = prime[i - 1];
                ans[1] = prime[i];
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