#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> map(3,0);
        int left = 0, right = 0, len = s.length();
        int ans = 0;
        while(right < len){
            map[s[right] - 'a']++;
            while(map[0] > 0 && map[1] > 0 && map[2] > 0){
                ans += len - right;
                map[s[left] - 'a']--;
                left++;
            }
            right++;
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
        cout << sol.numberOfSubstrings(input) << endl;
    }
    testcase.close();
    return 0;
}