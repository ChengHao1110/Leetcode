#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(k == 1) return true;
        vector<int> slots(k, 0);
        for(int i = 0; i < arr.size(); i++){
            // ex: -6 % 5 = -1, (-1 + 5) % 5 = 4 , -6 -> [4] (i.e., need to combine [1]) 
            int slot = ((arr[i] % k) + k) % k;
            slots[slot]++;
        }
        if(slots[0] % 2 != 0) return false;
        for(int i = 1; i <= k / 2; i++){
            if(slots[i] != slots[k - i]) return false;
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

    }
    testcase.close();
    return 0;
}