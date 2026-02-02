#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < nums.size() - 2; i++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                int k = j + 1, l, r, min = nums[j] - nums[i], max = nums[j] + nums[i];
                for(k; k < nums.size(); k++){
                    if(nums[k] > min){
                        l = k;
                        break;
                    }
                }
                if(k == nums.size()) break;
                for(k; k < nums.size(); k++){
                    if(nums[k] >= max){
                        r = k;
                        break;
                    }
                }
                if(k == nums.size()) r = nums.size();
                ans += r - l;
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