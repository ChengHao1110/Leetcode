#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int val = Direction('N', 'E', k, s);
        val = max(val, Direction('N', 'W', k, s));
        val = max(val, Direction('S', 'E', k, s));
        val = max(val, Direction('S', 'W', k, s));
        return val;
    }

    int Direction(char changeNS, char changeEW, int k, string s){
        int changeNSVal = (changeNS == 'S') ? 1 : -1, changeEWVal = (changeEW == 'W') ? 1 : -1;
        int x = 0, y = 0, val = 0;
        for(char c : s){
            if(k > 0 && (c == changeNS || c == changeEW)){
                if(c == changeNS){
                    y += changeNSVal;
                    k--;
                }
                else{
                    x += changeEWVal;
                    k--;
                }
            }
            else{
                switch (c)
                {
                case 'N':
                    y += 1;
                    break;
                case 'S':
                    y -= 1;
                    break;
                case 'E':
                    x += 1;
                    break;
                case 'W':
                    x -= 1;
                    break;
                }
            }
            val = max(val, abs(x) + abs(y));
        }
        return val;
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