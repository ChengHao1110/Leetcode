#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, full = capacity;
        for(int i = 0; i < plants.size(); i++){
            if(capacity >= plants[i]){
                steps++;
                capacity -= plants[i];
            }
            else{
                steps += 2 * (i + 1) - 1;
                capacity = full - plants[i];
            }
        }
        return steps;
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
        cout << sol.wateringPlants(arr, num) << endl;
    }
    testcase.close();
    return 0;
}