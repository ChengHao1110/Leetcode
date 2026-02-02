#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> s;
        for(auto a : arr) s.insert(a);
        int pre, cur, len, next, maxLength = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr.size() - i + 1 < maxLength) break;
            for(int j = i + 1; j < arr.size(); j++){
                pre = arr[i];
                cur = arr[j];
                next = pre + cur;
                if(s.find(next) == s.end()){
                    len = 0;
                }
                else{
                    len = 2;
                    while(s.find(next) != s.end()){
                    len++;
                    pre = cur;
                    cur = next;
                    next = pre + cur;
                    }
                }
                maxLength = max(maxLength, len);
            }
        }
        return maxLength;
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