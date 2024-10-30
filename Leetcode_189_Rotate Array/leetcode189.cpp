#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), curNum = nums[0], count = 0, pos = 0, temp;
        vector<bool> isPlaced(size, false);
        while(count < size){
            if(!isPlaced[pos]){
                isPlaced[pos] = true;
                pos = (pos + k) % size;
                temp = curNum;
                curNum = nums[pos];
                nums[pos] = temp;
                count++;
            }
            else{
                while(isPlaced[pos]){
                    pos++;
                    if(pos == size) pos = 0;
                }
                curNum = nums[pos];
            }
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
        int num;
        vector<int> arr;
        while(ss >> num) arr.push_back(num);
        arr.pop_back();
        sol.rotate(arr, num);
        for(int n : arr) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}