#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        char lastChar = ' ';
        pair<int, char> reserve;
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        while(!pq.empty()){
            pair<int, char> cur = pq.top();
            pq.pop();
            if(ans.length() >= 2 && cur.second == ans[ans.length() - 1] && cur.second == ans[ans.length() - 2]){
                //get another char
                if(pq.empty()) return ans;
                else{
                    //cout << "get duplicate " << cur.second << endl;
                    reserve = cur;
                    cur = pq.top();
                    //cout << "get another " << cur.second << endl;
                    pq.pop();
                    ans += cur.second;
                    cur.first --;
                    if(cur.first > 0) pq.push(cur);
                    pq.push(reserve);
                } 
            }
            else{
                ans += cur.second;
                cur.first --;
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
        int a, b ,c;
        ss >> a >> b >> c;
        cout << sol.longestDiverseString(a, b, c) << endl;
    }
    testcase.close();
    return 0;
}