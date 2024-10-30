#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        //do first -> change digits
        string newString = "";
        for(char ch : s){
            newString += to_string(ch - 'a' + 1);
        }
        for(int i = 0; i < k - 1; i++){
            int sum = 0;
            for(char ch : newString){
                sum += ch - '0';
            }
            newString = to_string(sum);
        }
        int ans = 0;
        for(char ch : newString){
            ans += ch - '0';
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
        stringstream ss(input);
        string s;
        int num;
        ss >> s >> num;
        cout << sol.getLucky(s, num) << endl;
    }
    testcase.close();
    return 0;
}