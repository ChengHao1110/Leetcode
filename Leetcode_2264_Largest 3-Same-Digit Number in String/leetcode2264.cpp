#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = ' ', maxCh = ' ';
        int times = 1;
        for(int i = 0; i < num.length(); i++){
            if(num[i] == ch){
                times++;
            }
            else{
                if(times > 2){
                    maxCh = max(maxCh, ch);
                }
                ch = num[i];
                times = 1;
            }
        }
        if(times > 2){
            maxCh = max(maxCh, ch);
        }

        string ans = "";
        if(maxCh >= '0' && maxCh <= '9'){
            for(int i = 0; i < 3; i++) ans += maxCh;
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