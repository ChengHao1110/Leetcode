#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> table;
        vector<string> order;
        for(string s : arr){
            if(table.find(s) != table.end()){
                table[s]++;
            }
            else{
                table.insert({s, 1});
                order.push_back(s);
            }
        }
        int distCount = 0;
        for(string s : order){
            if(table[s] == 1) distCount++;
            if(distCount == k) return s;
        }
        return "";
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
        string s;
        vector<string> arr;
        while(ss >> s) arr.push_back(s);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        int num;
        ss >> num;
        cout << sol.kthDistinct(arr, num) << endl;
    }
    testcase.close();
    return 0;
}