#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for(int i = 1; i < mountain.size() - 1; ){
            if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]){
                ans.push_back(i);
                i += 2;
            }
            else{
                i++;
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
        stringstream ss(input);
        int num;
        vector<int> arr, ans;
        while(ss >> num) arr.push_back(num);
        ans = sol.findPeaks(arr);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";    
        }
        cout << endl;
    }
    testcase.close();
    return 0;
}