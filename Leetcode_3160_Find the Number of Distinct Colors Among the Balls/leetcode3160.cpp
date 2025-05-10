#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colorFreq;
        unordered_map<int,int> ballsColor;
        //vector<int> balls(limit + 1, 0); // memory limit exceed
        vector<int> ans;
        for(auto q : queries){
            if(ballsColor.find(q[0]) != ballsColor.end()){
                colorFreq[ballsColor[q[0]]]--;
                if(colorFreq[ballsColor[q[0]]] == 0){
                    colorFreq.erase(ballsColor[q[0]]);
                }
                ballsColor[q[0]] = q[1];
            }
            else{
                ballsColor.insert({q[0], q[1]});
            }
            if(colorFreq.find(q[1]) != colorFreq.end()){
                colorFreq[q[1]]++;
            }
            else{
                colorFreq.insert({q[1], 1});
            }
            ans.push_back(colorFreq.size());
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