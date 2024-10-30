#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include <string.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        const char *d = "/";
        char *p = strtok(path.data(), d);
        while(p != NULL){
            //cout << p << endl;
            if(strcmp(p, "..") == 0){
                if(dirs.size() > 0) dirs.pop_back();
            }
            else if(strcmp(p, ".") != 0){
                dirs.emplace_back(p);
            }
            p = strtok(NULL, d);
        }
        string ans = "";
        if(dirs.size() == 1) return "/" + dirs[0];
        for(int i = 0; i < dirs.size(); i++){
            ans += "/" + dirs[i];
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
        cout << sol.simplifyPath(input) << endl;
    }
    testcase.close();
    return 0;
}