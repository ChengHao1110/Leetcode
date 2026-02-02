#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long areaA = (long long)(ax2 - ax1) * (long long)(ay2 - ay1), areaB = (long long)(bx2 - bx1) * (long long)(by2 - by1);
        if( (by1 >= ay2) || (by2 <= ay1) || (bx1 >= ax2) || (bx2 <= ax1)){
            return (int)(areaA + areaB);
        }
        //overlay
        long long overlayX, overlayY;
        // x
        if(bx1 >= ax1 && bx1 <= ax2){
            overlayX = min(ax2, bx2) - bx1;
        }
        else if(ax1 >= bx1 && ax1 <= bx2){
            overlayX = min(bx2, ax2) - ax1;
        }

        // y
        if(by1 >= ay1 && by1 <= ay2){
            overlayY = min(ay2, by2) - by1;
        }
        else if(ay1 >= by1 && ay1 <= by2){
            overlayY = min(by2, ay2) - ay1;
        }

        return (int)(areaA + areaB- overlayX * overlayY);
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