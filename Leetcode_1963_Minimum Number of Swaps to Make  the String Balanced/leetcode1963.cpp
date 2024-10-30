#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int count = 0, l = 0, r = s.length() - 1, swap = 0;
        while(l < s.length()){
            if(s[l] == '['){
                count++;
            }
            else{
                if(count == 0){
                    //swap
                    swap++;
                    while(s[r] != '['){
                        r--;
                    }
                    s[r] = ']';
                    count++;
                }
                else count--;
            }
            l++;
        }
        if(count > 0) swap += count / 2;
        return swap;
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