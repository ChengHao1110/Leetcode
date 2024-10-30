#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int **subArrayXORSum = new int*[arr.size()];
        int count = 0;
        for(int i = 0; i < arr.size(); i++) subArrayXORSum[i] = new int[arr.size()];
        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j < arr.size(); j++){
                if(i == j) subArrayXORSum[i][j] = arr[i];
                else subArrayXORSum[i][j] = subArrayXORSum[i][j-1] ^ arr[j];
                if(subArrayXORSum[i][j] == 0) count += j - i;
            }
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

    vector<int> nums;
    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        while(ss >> num){
            nums.push_back(stoi(num));
        }
        Solution sol;
        cout << sol.countTriplets(nums) << endl;
        nums.clear();
    }

    testcase.close();
    return 0;
}