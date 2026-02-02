#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> table;
        vector<bool> used(tiles.length(), false);
        BT(used, "", table, tiles);
        
        return table.size();
    }

    void BT(vector<bool> &used, string s, unordered_set<string> &table, string &tiles){
        for(int i = 0; i < tiles.length(); i++){
            if(!used[i]){
                string ori = s;
                s += tiles[i];
                used[i] = true;
                table.insert(s);
                BT(used, s, table, tiles);
                used[i] = false;
                s = ori;
            }
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