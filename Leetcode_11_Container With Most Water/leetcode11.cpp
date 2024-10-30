#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = INT_MIN, area = 0;
        while(left != right){
            area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else left++;
        }
        return maxArea;
    }
    
    int maxArea_tle(vector<int>& height) {
        int left = 0, right = 1;
        int maxArea = INT_MIN, area = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i + 1; j < height.size(); j++){
                area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
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
        stringstream ss (input);
        int num;
        vector<int> nums;
        while(ss >> num) nums.push_back(num);
        cout << "ans: " << sol.maxArea(nums) << endl;
    }
    testcase.close();
    return 0;
}