#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cnt = 0;
        vector<int> ans;
        vector<bool> usedA(A.size() + 1, false), usedB(A.size() + 1, false);
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i]){
                usedA[A[i]] = true;
                usedB[B[i]] = true;
                if(usedA[A[i]] && usedB[A[i]]) cnt++;
                if(usedA[B[i]] && usedB[B[i]]) cnt++;
            }
            else{
                cnt++;
            }
            ans.push_back(cnt);
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