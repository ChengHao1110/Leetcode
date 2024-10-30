#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;

        for(int i = 0; i <= (haystack.length() - needle.length()); i++){
            if(haystack[i] == needle[0]){
                int left = i + 1;
                bool find = true;
                for(int j = 1; j < needle.length(); j++, left++){
                    if(haystack[left] != needle[j]){
                        find = false;
                        break;
                    }
                }
                if(find) return i;
            }
        }
        return -1;
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
        string hay, need;
        ss >> hay >> need;
        cout << sol.strStr(hay, need) << endl;
    }
    testcase.close();
    return 0;
}