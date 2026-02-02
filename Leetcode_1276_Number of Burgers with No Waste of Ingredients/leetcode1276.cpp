#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = tomatoSlices - 2 * cheeseSlices, y = 0;
        if(x < 0 || x % 2 == 1) return vector<int>();
        x /= 2;
        y = cheeseSlices - x;
        if(y < 0) return vector<int>();
        return vector<int>{x, y};
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