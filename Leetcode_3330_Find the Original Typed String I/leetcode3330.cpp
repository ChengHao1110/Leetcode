#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, times = 1, i = 1;
        char curCh = word[0];
        while(i < word.size()){
            if(word[i] == curCh) times++;
            else{
                ans += times - 1;
                curCh = word[i];
                times = 1;
            }
            i++;
        }
        ans += times - 1;

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