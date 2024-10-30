#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        for(int k = 0; k < n; k++) nums1.pop_back();
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                i++;
                m++;
            }
            //for(int n : nums1) cout << n << " "; cout << endl;
        }
        if(i == m){
            for(j; j < n; j++) nums1.push_back(nums2[j]);
        }
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
        stringstream ss(input);
        int m, n;
        vector<int> arr1, arr2;
        ss >> m >> n;
        ss.clear();
        ss.str("");
        int num;
        getline(testcase, input);
        ss << input;
        while(ss >> num) arr1.push_back(num);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        while(ss >> num) arr2.push_back(num);
        sol.merge(arr1, m, arr2, n);
        for(int n : arr1) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}