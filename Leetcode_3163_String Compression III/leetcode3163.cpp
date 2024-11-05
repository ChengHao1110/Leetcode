#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        int idx = 1, count = 1;
        char curCh = word[0];
        string ans = "";
        while(idx < word.length()){
            if(word[idx] != curCh){
                int times = count / 9;
                for(int i = 0; i < times; i++){
                    ans += to_string(9);
                    ans += curCh;
                }
                count = count % 9;
                if(count > 0){
                    ans += to_string(count);
                    ans += curCh;
                }
                // change curCh
                curCh = word[idx];
                count = 1;
            }
            else{
                count++;
            }
            idx++;
        }
        int times = count / 9;
        for(int i = 0; i < times; i++){
            ans += to_string(9);
            ans += curCh;
        }
        count = count % 9;
        if(count > 0){
            ans += to_string(count);
            ans += curCh;
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
        cout << sol.compressedString(input) << endl;
    }
    testcase.close();
    return 0;
}