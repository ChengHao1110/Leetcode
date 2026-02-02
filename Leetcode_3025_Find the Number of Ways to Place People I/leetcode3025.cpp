#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        //(i, j) i: upper left (left hor || up ver || upper left)
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                if(i == j) continue;
                if(points[i][0] <= points[j][0] && points[i][1] >= points[j][1]){
                    // check whether any points in the rectangle
                    bool find = false;
                    for(int k = 0; k < points.size(); k++){
                        if(k == i || k == j) continue;
                        if(points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && points[k][1] >= points[j][1] && points[k][1] <= points[i][1]){
                            find = true;
                            break;
                        }
                    }
                    if(!find) ans++;
                }
            }
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