#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> openedBox;
        set<int> curKeys;
        set<int> notOpenedBoxes;
        for(int i = 0; i < initialBoxes.size(); i++){
            if(status[initialBoxes[i]] == 1){
                openedBox.push(initialBoxes[i]);
            }
            else{
                notOpenedBoxes.insert(initialBoxes[i]);
            }
        }

        int cnt = 0;
        while(!openedBox.empty()){
            int idx = openedBox.front();
            openedBox.pop();
            cnt += candies[idx];
            //get boxes
            for(int i = 0; i < containedBoxes[idx].size(); i++){
                if(status[containedBoxes[idx][i]] == 1){
                    openedBox.push(containedBoxes[idx][i]);
                }
                else{
                    notOpenedBoxes.insert(containedBoxes[idx][i]);
                }
            }
            //get keys
            for(int i = 0; i < keys[idx].size(); i++){
                if(status[keys[idx][i]] == 0) curKeys.insert(keys[idx][i]);
            }
            // match key and box
            for(set<int>::iterator i = notOpenedBoxes.begin(); i != notOpenedBoxes.end(); i++){
                auto it = curKeys.find(*i);
                if(it != curKeys.end()){
                    openedBox.push(*i);
                    notOpenedBoxes.erase(i);
                    curKeys.erase(it);
                }
            }
        }

        return cnt;
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