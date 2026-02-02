#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int len = 0, index = 0;
    string ans = "";
    string getHappyString(int n, int k) {
        int count = 0;
        len = n;
        index = k;
        ans = "";
        bool find = false;
        generate("", count, find);
        return ans;
    }

    void generate(string s, int &count, bool &find){
        if(find) return;
        if(s.length() == len){
            if(count == index - 1){
                ans = s;
                find = true;
                return;
            }
            else{
                count++;
                return;
            }
        }
        for(int i = 0; i < 3; i++){
            string ori = s;
            if(s.length() == 0 || s[s.length() - 1] != ('a' + i)){
                s += ('a' + i);
                generate(s, count, find);
            }
            s = ori;
        }
    }
};

int main(){
    Solution sol;
    cout << sol.getHappyString(3, 9) << endl;
    cout << sol.getHappyString(1, 3) << endl;
    cout << sol.getHappyString(1, 4) << endl;
    return 0;
}