#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        cout << "print arr(init): ";
        for(int n : this->nums) cout << n << " ";
        cout << endl;
    }
    
    int add(int val) {
        if(nums.size() == 0) nums.push_back(val);
        else{
            if(val <= nums[0]){
                nums.insert(nums.begin(), val);
            }
            else if(val >= nums[nums.size() - 1]){
                nums.push_back(val);
            }
            else{
                int index = BinarySearch(val, nums, 0, nums.size() - 1);
                nums.insert(nums.begin() + index, val);
            }
        }
        
        int ans = nums[nums.size() - k];
        return ans;
    }

    int BinarySearch(int val, vector<int>& nums, int low, int high){
        // return index
        while(high >= low){
            int mid = (low + high) / 2;
            if(nums[mid] == val){
                return mid;
            }
            else if(nums[mid] > val){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high + 1;
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
    
    while(getline(testcase, input)){
        stringstream ss(input);
        int k, num;
        ss >> k;
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        KthLargest sol(k, arr);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        while(ss >> num){
            cout << sol.add(num) << endl;
        }
    }
    testcase.close();
    return 0;
}