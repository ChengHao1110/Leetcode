#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> table;
        for(int num: barcodes){
            if(table.find(num) == table.end()) table[num] = 1;
            else table[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto iter = table.begin(); iter != table.end(); iter++){
            // {times, number}
            pq.push({iter->second, iter->first});
        }

        vector<int> ans;
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            if(ans.size() > 0 && ans.back() == cur.second){
                pair<int, int> another = pq.top();
                pq.pop();
                ans.push_back(another.second);
                another.first--;
                if(another.first > 0) pq.push(another);
                pq.push(cur);
            }
            else{
                ans.push_back(cur.second);
                cur.first--;
                if(cur.first > 0) pq.push(cur);
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
        vector<int> arr;
        int num;
        while(ss >> num) arr.push_back(num);
        arr = sol.rearrangeBarcodes(arr);
        for(int n : arr){
            cout << n << " ";
        }
        cout << endl;
    }
    testcase.close();
    return 0;
}