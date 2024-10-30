#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int count = 1, startIdx = 0;
        char lastChar = s[0];

        for(int i = 1; i < s.length(); i++){
            if(s[i] != lastChar){
                if(count >= 3){
                    vector<int> large;
                    large.push_back(startIdx);
                    large.push_back(i-1);
                    ans.push_back(large);
                }
                lastChar = s[i];
                startIdx = i;
                count = 1;
            }
            else{
                count++;
            }            
        }
        if(count >= 3){
            vector<int> large;
            large.push_back(startIdx);
            large.push_back(s.length()-1);
            ans.push_back(large);
        }
        
        return ans;
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
        vector<vector<int>> ans = sol.largeGroupPositions(input);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    testcase.close();
    return 0;
}