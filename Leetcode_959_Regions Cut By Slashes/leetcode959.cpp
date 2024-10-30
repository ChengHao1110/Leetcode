#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> parent, rank; // parent: group leader, rank: group size
    int faceCount = 0;

    int regionsBySlashes(vector<string>& grid) {
        const int row = grid.size();
        const int dots = row + 1;
        const int dotCount = dots * dots;
        faceCount = 0;
        //resize
        parent.resize(dotCount);
        rank.resize(dotCount);
        //initialize
        for(int i = 0; i < dotCount; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        //connect edge
        for(int i = 0; i < dots; i++){
            for(int j = 0; j < dots; j++){
                if(i == 0 || i == row || j == 0 || j == row){
                    int dotId = i * dots + j;
                    Union(0, dotId);
                }
            }
        }

        //connect slashes
        for(int i = 0; i < row; i++){
            string s = grid[i];
            for(int j = 0; j < row; j++){
                char ch = s[j];
                if(ch == '\\'){
                    int d1 = i * dots + j;
                    int d2 = (i + 1) * dots + j + 1;
                    Union(d1, d2);                    
                }
                else if(ch == '/'){
                    int d1 = (i + 1) * dots + j;
                    int d2 = i * dots + j + 1;
                    Union(d1, d2);
                }
            }
        }

        return faceCount;
    }

    void Union(int d1, int d2){
        int d1_Leader = FindLeader(d1), d2_Leader = FindLeader(d2);
        if(d1_Leader == d2_Leader) faceCount++;
        else{
            //merge group: merge small rank to big rank
            if(rank[d1_Leader] > rank[d2_Leader]){
                parent[d2_Leader] = d1_Leader;
            }
            else if(rank[d1_Leader] < rank[d2_Leader]){
                parent[d1_Leader] = d2_Leader;
            }
            else{
                parent[d2_Leader] = d1_Leader;
                rank[d1_Leader]++;
            }
        }
    }

    int FindLeader(int d){
        if(d == parent[d]) return d;
        return parent[d] = FindLeader(parent[d]);
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
        stringstream ss(input);
        int num;
        ss >> num;
        vector<string> grid;
        for(int i = 0; i < num; i++){
            getline(testcase, input);
            grid.push_back(input);
        }
        cout << sol.regionsBySlashes(grid) << endl;
    }
    testcase.close();
    return 0;
}