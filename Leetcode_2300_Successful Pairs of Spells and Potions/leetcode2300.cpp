#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);
        for(int i = 0; i < spells.size(); i++){
            long long val = spells[i];
            int low = 0, high = potions.size() - 1, mid = 0;
            while(low <= high){
                mid = (low + high) / 2;
                if(val * potions[mid] >= success){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            ans[i] = potions.size() - low;
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