#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for(int i = 0; i < target.size(); i++){
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> target, arr;
        int num;
        while(ss >> num) target.push_back(num);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        while(ss >> num) arr.push_back(num);
        if(sol.canBeEqual(target, arr)) cout << "TRUE" << endl;
        else cout << "False" << endl;
    }
    testcase.close();
    return 0;
}