#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, seen;
        for(int i = 0; i < arr.size(); i++){
            unordered_set<int> next;
            next.insert(arr[i]);
            for(auto n : seen){
                next.insert(arr[i] | n);
            }
            result.insert(next.begin(), next.end());
            seen = next;
        }
        return result.size();
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