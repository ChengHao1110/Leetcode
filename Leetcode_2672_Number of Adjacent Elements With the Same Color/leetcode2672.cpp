#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n, 0), ans(queries.size(), 0);
        int count = 0, pre = 0, next = 0, temp = 0;
        for(int i = 0; i < queries.size(); i++){
            temp = color[queries[i][0]];
            if(temp == queries[i][1]){
                ans[i] = count;
                continue;
            }
            color[queries[i][0]] = queries[i][1];
            pre = queries[i][0] - 1;
            next = queries[i][0] + 1;

            if(pre >= 0){
                if(color[pre] != 0){
                    if(temp != 0 && color[pre] == temp) count--;
                    if(color[pre] == color[queries[i][0]]) count++;
                }
            }
            if(next < n){
                if(color[next] != 0){
                    if(temp != 0 && color[next] == temp) count--;
                    if(color[next] == color[queries[i][0]]) count++;
                }
            }
            ans[i] = count;
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
        stringstream ss(input);
        int n, times, idx, color;
        vector<vector<int>> queries;
        ss >> n >> times;
        ss.clear();
        ss.str("");
        for(int i = 0; i < times; i++){
            getline(testcase, input);
            ss << input;
            ss >> idx >> color;
            vector<int> query;
            query.push_back(idx);
            query.push_back(color);
            queries.push_back(query);
            ss.clear();
            ss.str("");
        }
        vector<int> ans = sol.colorTheArray(n, queries);
        for(int a : ans) cout << a << " "; cout << endl;
    }
    testcase.close();
    return 0;
}