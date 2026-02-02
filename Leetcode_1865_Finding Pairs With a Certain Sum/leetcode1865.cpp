#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class FindSumPairs {
public:
    unordered_map<int, int> v1, v2;
    vector<int> *nums2Copy;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = unordered_map<int, int>();
        v2 = unordered_map<int, int>();
        nums2Copy = &nums2;
        for(int n : nums1) v1[n]++;
        for(int n : nums2) v2[n]++;
    }
    
    void add(int index, int val) {
        v2[(*nums2Copy)[index]]--;
        (*nums2Copy)[index] += val;
        v2[(*nums2Copy)[index]]++;
    }
    
    int count(int tot) {
        int ans = 0, target = 0;
        for(auto t : v1){
            target = tot - t.first;
            if(v2.find(target) != v2.end()){
                ans += t.second * v2[target];
            }
        }
        return ans;
    }
};


int main(){

}