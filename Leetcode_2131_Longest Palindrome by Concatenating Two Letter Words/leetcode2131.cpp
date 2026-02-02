#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> diff, same;
        for(int i = 0; i < words.size(); i++){
            if(words[i][0] == words[i][1]){
                same[words[i]]++;
            }
            else{
                diff[words[i]]++;
            }
        }

        int length = 0;
        for(auto d : diff){
            string rev = d.first;
            reverse(rev.begin(), rev.end());
            if(diff.find(rev) != diff.end() && d.second != 0){
                int match = min(d.second, diff[rev]);
                length += 4 * match;
                d.second = 0;
                diff[rev] = 0;
            }
        }
        bool center = false;
        for(auto s : same){
            if(s.second % 2 == 1) center = true;
            if(s.second > 1) length += (s.second / 2) * 4;
        }
        if(center) length += 2;
        return length;
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