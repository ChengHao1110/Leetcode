#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> table;
        int cnt = 0, l = 0, r = 0, ans = 0, len = 0;

        while(r < fruits.size()){
            table[fruits[r]]++;

            if(table.size() > 2){
                ans = max(ans, len);
                len++; // add current fruit
                while(table.size() > 2){
                    table[fruits[l]]--;
                    len--;
                    if(table[fruits[l]] == 0){
                        table.erase(fruits[l]);
                    }
                    l++;
                }
            }
            else{
                len++;
            }
           
            r++;
        }

        ans = max(ans, len);

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