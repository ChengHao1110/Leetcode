#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string ori = q.front();
            q.pop();
            string add = Add(ori, a), rot = Rotate(ori, b);
            if(visited.find(add) == visited.end()){
                q.push(add);
                visited.insert(add);
            }
            if(visited.find(rot) == visited.end()){
                q.push(rot);
                visited.insert(rot);
            }
        }

        return *visited.begin();
    }

    string Add(string s, int n){
        for(int i = 1; i < s.length(); i += 2){
            s[i]= ( ((s[i] - '0') + n) % 10 ) + '0';
        }
        return s;
    }

    string Rotate(string s, int n){
        string result = s;
        int idx = 0, len = s.length();
        for(int i = 0; i < len; i++){
            idx = (i + n) % len;
            result[idx] = s[i];
        }
        return result;
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