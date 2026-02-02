#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        for(int i = 0; i < points.size() - 2; i++){
            for(int j = i + 1; j < points.size() - 1; j++){
                for(int k = j + 1; k < points.size(); k++){
                    maxArea = max(maxArea, GetArea(points[i], points[j], points[k]));
                }
            }
        }
        return maxArea;
    }

    double GetArea(vector<int> x, vector<int> y, vector<int> z){
        return abs(0.5 * ( (x[0] * y[1] - y[0] * x[1]) + (y[0] * z[1] - z[0] * y[1]) + (z[0] * x[1] - x[0] * z[1]) ));
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