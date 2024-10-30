#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> fMax(height.size(), 0), bMax(height.size(), 0);
        int lMax = INT_MIN, rMax = INT_MIN, count = 0;
        for(int i = 0; i < height.size(); i++){
            if(height[i] > lMax){
                lMax = height[i];
                fMax[i] = lMax;
            }
            else{
                fMax[i] = lMax;
            }
            if(height[height.size() - 1 - i] > rMax){
                rMax = height[height.size() - 1 - i];
                bMax[height.size() - 1 - i] = rMax;
            }
            else{
                bMax[height.size() - 1 - i] = rMax;
            }
        }
        //for(int n : fMax) cout << n << " "; cout << endl;
        //for(int n : bMax) cout << n << " "; cout << endl;
        for(int i = 0; i < height.size(); i++){
            count += min(fMax[i], bMax[i]) - height[i];
        }
        return count;
    }

    int trap_tle(vector<int>& height) {
        // Time Limit Exceeded
        int startIdx = 0, lMax = 0, rMax = 0, minMax = 0, count = 0;
        while(startIdx < height.size() && height[startIdx] == 0) startIdx++;
        for(int i = startIdx + 1; i < height.size() - 1; i++){
            //cout << i << endl;
            //for(vector<int>::iterator j = height.begin() + startIdx; j <= height.begin() + i; j++) cout << *j << " "; cout << endl;
            //for(vector<int>::iterator j = height.begin() + i; j < height.end(); j++) cout << *j << " "; cout << endl;
            lMax = *max_element(height.begin() + startIdx, height.begin() + i + 1);
            rMax = *max_element(height.begin() + i, height.end());
            //cout <<"lMax: " << lMax << " rMax: " << rMax << endl;
            minMax = min(lMax, rMax);
            count += minMax - height[i];
        }
        return count;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> nums;
        int num;
        while(ss >> num) nums.push_back(num);
        cout << sol.trap(nums) << endl;
    }
    testcase.close();
    return 0;
}