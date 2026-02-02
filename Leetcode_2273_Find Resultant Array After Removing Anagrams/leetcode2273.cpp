#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        vector<int> curFreq(26, 0);
        for(int j = 0; j < words[0].length(); j++) curFreq[words[0][j] - 'a']++;

        for(int i = 1; i < words.size(); i++){
            vector<int> freq(26, 0);
            for(int j = 0; j < words[i].length(); j++) freq[words[i][j] - 'a']++;
            bool same = true;
            for(int j = 0; j < 26; j++){
                if(freq[j] != curFreq[j]){
                    same = false;
                    curFreq = freq;
                }
            }
            if(!same) ans.push_back(words[i]);
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