#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> table;
        for(int i = 1; i <= n; i++){
            int sum = 0, num = i;
            while(num > 0){
                sum += (num % 10);
                num /= 10;
            }
            table[sum]++;
        }
        int max = INT_MIN, ans = 0;
        for(unordered_map<int, int>::iterator iter = table.begin(); iter != table.end(); iter++){
            if(iter->second > max){
                max = iter->second;
                ans = 1;
            }
            else if(iter->second == max){
                ans++;
            }
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