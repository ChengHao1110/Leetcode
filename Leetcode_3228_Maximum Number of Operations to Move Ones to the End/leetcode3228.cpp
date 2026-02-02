#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int cntOnes = 0, i = 0, ans = 0;
        bool continueOnes = false;
        while(i < s.length()){
            if(s[i] == '1'){
                cntOnes = 1;
                continueOnes = true;
                i++;
                break;
            }
            i++;
        }

        while(i < s.length()){
            if(s[i] == '1'){
                if(!continueOnes) ans += cntOnes;
                cntOnes++;
                continueOnes = true;
            }
            else{
                continueOnes = false;
            }
            i++;
        }

        if(!continueOnes) ans += cntOnes;
        
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