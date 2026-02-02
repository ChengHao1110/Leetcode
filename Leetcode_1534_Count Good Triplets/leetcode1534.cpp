#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < arr.size() - 2; i++){
            for(int j = i + 1; j < arr.size() - 1; j++){
                if(abs(arr[i] - arr[j]) <= a){
                    for(int k = j + 1; k < arr.size(); k++){
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) ans++;
                    }
                }
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

    }
    testcase.close();
    return 0;
}