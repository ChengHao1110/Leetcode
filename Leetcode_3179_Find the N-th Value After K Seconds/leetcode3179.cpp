#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long m = 1000000007;
    int valueAfterKSeconds(int n, int k) {
        vector<long long> arr(n, 1);
        for(int i = 0; i < k; i++){
            for(int j = 1; j < n; j++) arr[j] = (arr[j - 1] + arr[j]) % m;
        }
        return (int)arr[n - 1];
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