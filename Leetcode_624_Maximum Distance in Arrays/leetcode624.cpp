#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

bool CMPforMax(pair<int, int> p1, pair<int, int> p2){
    return p1.first > p2.first;
}

bool CMPforMin(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> max, min;
        for(int i = 0; i < arrays.size(); i++){
            min.push_back({arrays[i][0], i});
            max.push_back({arrays[i][arrays[i].size()-1], i});
        }
        sort(min.begin(), min.end(), CMPforMin);
        sort(max.begin(), max.end(), CMPforMax);
        if(max[0].second != min[0].second) return max[0].first - min[0].first;
        else{
            if((max[0].first - min[1].first) > (max[1].first - min[0].first)) return max[0].first - min[1].first;
            else return max[1].first - min[0].first;
        }
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
        int times;
        ss >> times;
        ss.clear();
        ss.str("");
        vector<vector<int>> arrs;
        while(times--){
            getline(testcase, input);
            vector<int> arr;
            int num;
            ss << input;
            while(ss >> num) arr.push_back(num);
            arrs.push_back(arr);
            ss.clear();
            ss.str("");
        }
        cout << "ans: " << sol.maxDistance(arrs) << endl;
    }
    testcase.close();
    return 0;
}