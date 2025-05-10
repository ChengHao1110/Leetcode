#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
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
        arr = sol.finalPrices(arr);
        for(int a : arr) cout << a << " ";
        cout << endl;
    }
    testcase.close();
    return 0;
}