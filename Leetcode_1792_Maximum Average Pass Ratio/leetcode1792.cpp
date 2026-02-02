#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int total = classes.size();
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        //{diff_avg, classIdx}
        for(int i = 0; i < total; i++){
            pq.push({ ((double)(classes[i][0] + 1) / (classes[i][1] + 1)) - ((double)classes[i][0] / classes[i][1]), i});
        }

        for(int i = 0; i < extraStudents; i++){
            auto [diff, idx] = pq.top();
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push({ ((double)(classes[idx][0] + 1) / (classes[idx][1] + 1)) - ((double)classes[idx][0] / classes[idx][1]), idx});
        }

        double ans = 0;
        for(int i = 0; i < total; i++){
            ans += (double)classes[i][0] / classes[i][1];
        }
        return ans / total;
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