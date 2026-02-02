#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0], mid, cnt;
        while(low < high){
            mid = (low + high) / 2;
            cnt = 0;
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i + 1] - nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= p){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
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