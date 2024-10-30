#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) return 1;
        int idx = -1, move = 2, end = n;

        while(n >= 1){
            idx += move;
            cout << "n: " << n << " idx: " << idx << endl;
            if(move > 0){
                if(idx < end) n--;
                else if(idx == end){
                    idx--;
                    cout << "n: " << (n-1) << " idx(change): " << idx << endl;
                    n -= 2;
                    move *= -2;
                }
                else{
                    idx -= move / 2;
                    if(idx > end) idx -= move;
                    cout << "n: " << n << " idx(change): " << idx << endl;
                    move *= -2;
                    n--;
                }
            }
            else{
                if(idx > 0) n--;
                else{
                    idx -= move / 2;
                    if(idx <= 0) idx -= move;
                    cout << "n: " << n << " idx(change): " << idx << endl;
                    move *= -2;
                    n--;
                }
            }
            
        }
        return idx;
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
        cout << sol.lastRemaining(stoi(input)) << endl;
    }
    testcase.close();
    return 0;
}