#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minVal = 0, l = 0, r = 0, white = 0;
        for(r; r < k; r++){
            if(blocks[r] == 'W') white++;
        }
        minVal = white;
        if(minVal == 0) return minVal;

        while(r < blocks.length()){
            if(blocks[r] == 'W') white++;
            if(blocks[l] == 'W') white--;
            r++;
            l++;
            minVal = min(minVal, white);
        }

        return minVal;
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