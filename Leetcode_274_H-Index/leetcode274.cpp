#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0, curH = 0;
        for(int i = 0; i < n; i++){
            curH = min(citations[i], n - i);
            h = max(h, curH);
        }
        return h;
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
        vector<int> arr;
        int num;
        stringstream ss(input);
        while(ss >> num) arr.push_back(num);
        cout << sol.hIndex(arr) << endl;
    }
    testcase.close();
    return 0;
}