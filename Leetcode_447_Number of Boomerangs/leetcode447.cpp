#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<long, int> dist;
            for(int j = 0; j < points.size(); j++){
                if(i == j) continue;
                long d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                dist[d]++;
            }

            for(auto d : dist){
                if(d.second > 1) ans += d.second * (d.second - 1);
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