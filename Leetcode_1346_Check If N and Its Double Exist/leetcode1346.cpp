#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        int zeroCnt = 0;
        for(int n : arr){
            s.insert(n);
            if(n == 0){
                zeroCnt++;
                if(zeroCnt == 2) return true;
                continue;
            } 
            if(s.find(2 * n) != s.end()) return true;
            if(n % 2 == 0 && s.find(n / 2) != s.end()) return true;
        }
        return false;
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