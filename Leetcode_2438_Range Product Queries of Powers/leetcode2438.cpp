#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    long long m = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power2(31, 0);
        power2[0] = 1;
        for(int i = 1; i < 31; i++) power2[i] = 2 * power2[i - 1];
        
        vector<long long> nums;
        for(int i = 30; i >= 0; i--){
            if(n >= power2[i]){
                nums.push_back(power2[i]);
                n -= power2[i];
            }
        }

        reverse(nums.begin(), nums.end());

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            long long num = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; j++){
                num = num * nums[j] % m;
            }
            ans.push_back(num);
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