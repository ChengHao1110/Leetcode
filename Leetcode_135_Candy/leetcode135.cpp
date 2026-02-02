#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<numeric>
#include<algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]) ans[i] = ans[i - 1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]) ans[i] = max(ans[i], ans[i + 1] + 1);
        }
        int cnt = accumulate(ans.begin(), ans.end(), 0);
        return cnt;
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