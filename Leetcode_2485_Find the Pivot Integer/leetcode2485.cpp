#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, sL = 1, sR = n;
        while(l <= r){
            if(sL < sR){
                sL += (++l);
            }
            else if(sL == sR){
                if(l != r){
                    sL += (++l);
                    sR += (--r);
                }
                else{
                    return l;
                }
            }
            else{
                sR += (--r);
            }
        }
        return -1;
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
        cout << sol.pivotInteger(stoi(input)) << endl;
    }
    
    testcase.close();
    return 0;
}