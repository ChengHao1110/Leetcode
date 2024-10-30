#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct_ver1(vector<int>& nums, int k) {
        // time limit
        unordered_map<int, int> map, tmp_map;
        int l = 0, r = 0, tmp = 0, count = 0;
        while(r < nums.size()){
            map[nums[r]]++;
            if(map.size() == k){
                count++;
                //cout << "count++" << endl;
                //cout << "l: " << l << " r: " << r << endl;
            }
            else if(map.size() > k){
                while(map.size() != k){
                    map[nums[l]]--;
                    if(map[nums[l]] == 0) map.erase(nums[l]);
                    l++;
                }
                count++;
                //cout << "count++" << endl;
                //cout << "l: " << l << " r: " << r << endl;  
            }
            tmp = l;
            tmp_map = map;
            while(tmp + (k-1) < r){
                tmp_map[nums[tmp]]--;
                if(tmp_map[nums[tmp]] == 0) tmp_map.erase(nums[tmp]);
                tmp++;
                if(tmp_map.size() == k){
                    count++;
                    //cout << "count++" << endl;
                    //cout << "tmp: " << tmp << " r: " << r << endl;
                }
            }
            tmp_map.clear();

            r++;
        }
        return count;
    }

    int subarraysWithKDistinct_ver2(vector<int>& nums, int k) {
        // solution: 程K俱计皚计秖 - 程K-1俱计皚计秖 = K俱计皚计秖
        unordered_map<int, int> map;
        int l = 0, r = 0, KCount = 0, LessThanKCount = 0;
        // calculate KCount
        while(r < nums.size()){
            map[nums[r]]++;
            if(map.size() <= k){
                KCount += r - l + 1;
            }
            else{
                while(map.size() != k){
                    map[nums[l]]--;
                    if(map[nums[l]] == 0) map.erase(nums[l]);
                    l++;
                }
                KCount += r - l + 1; 
            }
            r++;
        }
        map.clear();
        l = 0;
        r = 0;
        // calculate LessThanKCount
        while(r < nums.size()){
            map[nums[r]]++;
            if(map.size() <= k - 1){
                LessThanKCount += r - l + 1;
            }
            else{
                while(map.size() != k - 1){
                    map[nums[l]]--;
                    if(map[nums[l]] == 0) map.erase(nums[l]);
                    l++;
                }
                LessThanKCount += r - l + 1; 
            }
            r++;
        }
        return KCount - LessThanKCount;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    vector<int> nums;
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        int target = nums.back();
        nums.pop_back(); 
        Solution sol;
        //cout << "count: " << sol.subarraysWithKDistinct_ver1(nums, target) << endl;
        cout << "count: " << sol.subarraysWithKDistinct_ver1(nums, target) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}