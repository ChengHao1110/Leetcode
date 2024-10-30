#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> points;
        pair<int, int> cur = {0, 0};
        points.insert(cur);
        for(char c : path){
            switch(c){
                case 'N':
                    cur.second += 1;
                break;
                case 'E':
                    cur.first += 1;
                break; 
                case 'S':
                    cur.second -= 1;
                break; 
                case 'W':
                    cur.first -= 1;
                break;  
            }
            if(!points.count(cur)) points.insert(cur);
            else return true;
        }
        return false;
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
        cout << sol.isPathCrossing(input) << endl;
    }
    return 0;
}