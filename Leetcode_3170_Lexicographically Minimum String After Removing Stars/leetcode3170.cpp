#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Compare{
public:
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2){
        if(p1.first > p2.first) return true;
        else if(p1.first < p2.first) return false;
        else{
            if(p1.second > p2.second) return false;
            else return true;
        }
    }
};

class Solution {
public:
    string clearStars(string s) {
        vector<bool> removed(s.length(), false);
        priority_queue< pair<char, int>, vector<pair<char, int>>, Compare > pq;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '*'){
                pq.push({s[i], i});
            }
            else{
                removed[pq.top().second] = true;
                pq.pop();
            }
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(!removed[i] && s[i] != '*') ans += s[i];
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