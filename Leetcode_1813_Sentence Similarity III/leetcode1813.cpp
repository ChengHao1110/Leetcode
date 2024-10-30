#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream s1(sentence1), s2(sentence2);
        string str;
        vector<string> sArr1, sArr2;
        while(s1 >> str) sArr1.push_back(str);
        while(s2 >> str) sArr2.push_back(str);
        if(sArr1.size() < sArr2.size()){
            vector<string> temp = sArr1;
            sArr1 = sArr2;
            sArr2 = temp;
        }

        int prefixLen = 0, suffixLen = 0;
        int idx1 = 0, idx2 = 0;
        for(idx2; idx2 < sArr2.size(); idx2++, idx1++){
            if(sArr1[idx1] == sArr2[idx2]) prefixLen++;
            else break;
        }
        idx1 = sArr1.size() - 1;
        idx2 = sArr2.size() - 1;
        for(idx2; idx2 >= 0; idx2--, idx1--){
            if(sArr1[idx1] == sArr2[idx2]) suffixLen++;
            else break;
        }
        if(prefixLen + suffixLen >= sArr2.size()) return true;
        else return false;
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