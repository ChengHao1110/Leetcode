#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            vector<int> subarray;
            if(r[i] - l[i] == 1) ans.push_back(true);
            else{
                for(int j = l[i]; j <= r[i]; j++){
                    subarray.push_back(nums[j]);
                }
                sort(subarray.begin(), subarray.end());
                int diff = subarray[1] - subarray[0];
                bool isArithmetic = true;
                for(int j = 2; j < subarray.size(); j++){
                    if(subarray[j] - subarray[j - 1] != diff){
                        ans.push_back(false);
                        isArithmetic = false;
                        break;
                    }
                }
                if(isArithmetic) ans.push_back(true);
            }
        }
        return ans;
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
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> nums, l, r;
        int num;
        while(ss >> num) nums.push_back(num);
        ss.clear();
	    ss.str("");
        // l
        getline(testcase, input);
        ss << input;
        while(ss >> num) l.push_back(num);
        ss.clear();
        ss.str("");
        // r
        getline(testcase, input);
        ss << input;
        while(ss >> num) r.push_back(num);
        Solution sol;
        vector<bool> ans = sol.checkArithmeticSubarrays(nums, l, r);
        for(bool b : ans) cout << b << " "; cout << endl;
    }
    return 0;
}