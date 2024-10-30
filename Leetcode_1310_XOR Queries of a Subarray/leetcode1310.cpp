#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> PreXorSum(arr.size(), 0);
        PreXorSum[0] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            PreXorSum[i] = PreXorSum[i - 1] ^ arr[i]; 
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == queries[i][1]){
                ans.emplace_back(arr[queries[i][0]]);
            }
            else{
                if(queries[i][0] != 0) ans.emplace_back(PreXorSum[queries[i][1]] ^ PreXorSum[queries[i][0] - 1]);
                else ans.emplace_back(PreXorSum[queries[i][1]]);
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