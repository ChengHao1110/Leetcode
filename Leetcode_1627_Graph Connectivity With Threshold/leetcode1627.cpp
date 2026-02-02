#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = threshold + 1; 2 * i <= n; i++){
            if(parent[i] != i) continue;
            int nextI = 2 * i;
            while(nextI <= n){
                Union(i, nextI);
                nextI += i;
            }
        }

        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++){
            if(Find(queries[i][0]) == Find(queries[i][1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){
        int parentX = Find(x), parentY = Find(y);
        if(parentX == parentY) return;
        else if(parentX < parentY){
            parent[parentY] = parentX;
        }
        else{
            parent[parentX] = parentY;
        }
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