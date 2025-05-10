#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int i = 0;
        while(i < address.length()){
            if(address[i] == '.'){
                address.replace(address.begin() + i, address.begin() + i + 1, "[.]");
                i += 3;
            }
            else{
                i++;
            }
        }
        return address;
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
        cout << sol.defangIPaddr(input) << endl;
    }
    testcase.close();
    return 0;
}