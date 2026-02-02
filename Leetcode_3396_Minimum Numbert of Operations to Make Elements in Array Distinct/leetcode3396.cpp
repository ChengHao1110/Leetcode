#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int ,int> table;
        for(int n : nums) table[n]++;
        int cnt = 0, idx = 0;
        bool duplicated;
        do{
            duplicated = false;
            for(auto t : table){
                if(t.second > 1){
                    duplicated = true;
                    break;
                }
            }
            if(duplicated){
                cnt++;
                for(int i = 0; i < 3 && idx < nums.size(); i++){
                    table[nums[idx]]--;
                    idx++;
                }
            }
        }while(duplicated);

        return cnt;
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