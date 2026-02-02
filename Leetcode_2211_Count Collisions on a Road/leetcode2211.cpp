#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        char cur = directions[0];
        int ans = 0, cnt = 1;
        for(int i = 1; i < directions.length(); i++){
            if(directions[i] != cur){
                if(cur == 'R'){
                    //(R, L)
                    if(directions[i] == 'L'){
                        ans += (cnt + 1);
                    }
                    //(R, S)
                    else{
                        ans += cnt;
                    }
                    cur = 'S';
                    cnt = 0;
                }
                else if(cur == 'S'){
                    //(S, L)
                    if(directions[i] == 'L'){
                        ans++;
                        cur = 'S';
                        cnt = 0;
                    }
                    else{
                        cur = 'R';
                        cnt = 1;
                    }  
                }
                else{
                    cur = directions[i];
                    if(cur == 'R') cnt = 1;
                    else cnt = 0;
                }
            }
            //same direction
            else{
                cnt++;
            }
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

    }
    testcase.close();
    return 0;
}