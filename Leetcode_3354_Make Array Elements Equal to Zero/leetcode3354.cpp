#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];
        int ans = 0, sum = prefix[n - 1];
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(i == 0 || i == n - 1){
                    if(sum == 0) ans += 2;
                    else if(sum == 1) ans++;
                }
                else{
                    if(prefix[i] == sum - prefix[i]) ans += 2;
                    else if(prefix[i] == sum - prefix[i] + 1) ans++;
                    else if(prefix[i] + 1 == sum - prefix[i]) ans++;
                }
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