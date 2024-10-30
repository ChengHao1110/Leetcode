#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        while(tickets[k] != 0){
            for(int i = 0; i < tickets.size(); i++){
                tickets[i]--;
                count++;
                if(tickets[i] == 0){
                    if(i == k) return count;
                    if(i < k){
                        tickets.erase(tickets.begin() + i);
                        k--;
                    }
                    if(i > k){
                        tickets.erase(tickets.begin() + i);
                    }
                    i--;
                }
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

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> nums;
        int num;
        while(ss >> num) nums.push_back(num);
        getline(testcase, input);
        cout << "Ans: " << sol.timeRequiredToBuy(nums, stoi(input)) << endl;
    }
    testcase.close();
    return 0;
}