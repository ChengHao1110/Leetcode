#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coin(3, 0);
        int count = 0;
        for(int b : bills){
            switch (b)
            {
            case 5:
                coin[0]++;
                break;
            case 10:
                if(coin[0] > 0){
                    coin[0]--;
                    coin[1]++;
                }
                else return false;
                break;
            case 20:
                if(coin[1] > 0 && coin[0] > 0){
                    coin[0]--;
                    coin[1]--;
                    coin[2]++;
                }
                else if (coin[0] > 2){
                    coin[0] -= 3;
                    coin[2]++;
                }
                else return false;
                break;
            }
        }
        return true;
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
        stringstream ss(input);
        vector<int> arr;
        int num;
        while(ss >> num) arr.push_back(num);
        if(sol.lemonadeChange(arr)) cout << "True" << endl;
        else cout << "False" << endl;
    }
    testcase.close();
    return 0;
}