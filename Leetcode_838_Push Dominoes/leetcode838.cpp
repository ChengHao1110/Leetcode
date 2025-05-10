#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<char, int>> d(dominoes.length());
        int i = 0;
        while(i < dominoes.length()){
            if(dominoes[i] == '.'){
                d[i] = {'.', 0};
                i++;
            }
            else if(dominoes[i] == 'L'){
                d[i] = {'L', 0};
                int idx = i - 1, cnt = 1;
                while(idx > -1){
                    if(d[idx].first == '.'){
                        d[idx] = {'L', cnt};
                        cnt++;
                    }
                    else if(d[idx].first == 'L') break;
                    else{
                        if(d[idx].second > cnt){
                            d[idx] = {'L', cnt};
                            cnt++;
                        }
                        else if(d[idx].second == cnt){
                            d[idx] = {'.', 0};
                            break;
                        }
                        else{
                            break;
                        }
                    }
                    idx--;
                }
                i++;
            }
            else{
                d[i] = {'R', 0};
                int idx = i + 1, cnt = 1;
                while(idx < dominoes.length()){
                    if(dominoes[idx] == '.'){
                        d[idx] = {'R', cnt};
                        cnt++;
                    }
                    else break;
                    idx++;
                }
                i = idx;
            }
            for(int j= 0; j < dominoes.length(); j++){
                cout << "(" << d[j].first << ", " << d[j].second << "), ";
            }
            cout << endl;
        }
        string ans = "";
        i = 0;
        while(i < dominoes.length()){
            ans += d[i].first;
            i++;
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