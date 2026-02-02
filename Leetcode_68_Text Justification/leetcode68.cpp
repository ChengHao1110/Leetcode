#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curLen = 0, curWords = 0, i = 0;
        vector<string> ans;
        while(i < words.size()){
            int newLen = curLen + words[i].length();
            if(words[i][words[i].length() - 1] == '.') newLen--;
            if(newLen < maxWidth){
                curLen = newLen + 1; //add space
                curWords++;
                i++;
            }
            else if(newLen == maxWidth){
                string s = "";
                if(curWords + 1 == 1){ //add current word (words[i])
                    s = words[i];
                }
                else{
                    for(int j = i - curWords; j < i; j++){
                        s += words[j] + " ";
                    }
                    s += words[i];
                }
                ans.push_back(s);
                i++;

                //new line
                curLen = 0;
                curWords = 0;
            }
            else{
                string s = "";
                if(curWords == 1){
                    s = words[i - 1];
                    int spaceCnt = maxWidth - s.length();
                    for(int j = 0; j < spaceCnt; j++) s += " ";
                }
                else{
                    int slots = (curWords - 1);
                    int spaceCnt = maxWidth - (curLen - 1 - slots); // -1 : remove last space
                    int spaceLen = spaceCnt / slots, redundentSpace = spaceCnt % slots;

                    for(int j = i - curWords; j < i - 1; j++){
                        s += words[j];
                        int add = (redundentSpace > 0) ? 1 : 0;
                        for(int k = 0; k < spaceLen + add; k++){
                            s += " ";
                        }
                        redundentSpace--;
                    }
                    s += words[i - 1];
                }
                ans.push_back(s);

                //new line
                curLen = 0;
                curWords = 0;
            }
        }

        //left-justified
        if(curLen != 0){
            int spaceCnt = maxWidth - curLen;
            string s = "";
            for(int j = i - curWords; j < i; j++){
                s += words[j] + " ";
            }
            for(int j = 0; j < spaceCnt; j++) s += " ";
            ans.push_back(s);
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