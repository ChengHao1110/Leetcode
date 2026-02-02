#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0, n = fruits.size();
        vector<bool> used(n, false);
        for(int i = 0; i < n; i++){
            bool unplaced = true;
            for(int j = 0; j < n; j++){
                if(!used[j] && baskets[j] >= fruits[i]){
                    used[j] = true;
                    unplaced = false;
                    break;
                }
            }
            if(unplaced) ans++;
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