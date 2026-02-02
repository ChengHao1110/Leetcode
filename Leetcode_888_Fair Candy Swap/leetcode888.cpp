#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long totalAlice = 0, totalBob = 0;
        unordered_set<int> alice, bob;
        for(int n : aliceSizes){
            totalAlice += n;
            alice.insert(n);
        }
        for(int n : bobSizes){
            totalBob += n;
            bob.insert(n);
        }
        if(totalAlice > totalBob){
            long long diff = (totalAlice - totalBob) / 2;
            for(int n : bobSizes){
                if(alice.find(n + diff) != alice.end()){
                    return vector<int>{n + (int)diff, n};
                }
            }
        }
        else{
            long long diff = (totalBob - totalAlice) / 2;
            for(int n : aliceSizes){
                if(bob.find(n + diff) != bob.end()){
                    return vector<int>{n, n + (int)diff};
                }
            }
        }

        return {-1, -1};
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