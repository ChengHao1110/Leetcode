#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int *p = new int[2];
        p[0] = 0;
        p[1] = 0;
        for(int i = 0; i < moves.length(); i++){
            switch (moves[i])
            {
            case 'U':
                p[1]++;
                break;
            case 'R':
                p[0]++;
                break;
            case 'D':
                p[1]--;
                break;
            case 'L':
                p[0]--;
                break;
            }
        }
        return (p[0] == 0 && p[1] == 0);
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
        if(sol.judgeCircle(input)) cout << "True" << endl;
        else cout << "False" << endl;
    }
    testcase.close();
    return 0;
}