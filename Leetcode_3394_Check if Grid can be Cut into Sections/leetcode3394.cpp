#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            //horizontal: y-axis
            int line = 0;
            sort(rectangles.begin(), rectangles.end(), cmp_hor);
            int cur_y = rectangles[0][3];
            for(int i = 1; i < rectangles.size(); i++){
                if(rectangles[i][1] >= cur_y){
                    line++;
                }
                cur_y = max(cur_y, rectangles[i][3]);
                if(line == 2) return true;
            }
            
            //vertical: x-axis
            line = 0;
            sort(rectangles.begin(), rectangles.end(), cmp_ver);
            int cur_x = rectangles[0][2];
            for(int i = 1; i < rectangles.size(); i++){
                if(rectangles[i][0] >= cur_x){
                    line++;
                }
                cur_x = max(cur_x, rectangles[i][2]);
                if(line == 2) return true;
            }
    
            return false;
        }
    
        static bool cmp_hor(const vector<int> &r1, const vector<int> &r2){
            if(r1[1] < r2[1]) return true;
            else return false;
        }
    
        static bool cmp_ver(vector<int> &r1, const vector<int> &r2){
            if(r1[0] < r2[0]) return true;
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
        stringstream ss(input);
        int n, cnt;
        ss >> n >> cnt;
        vector<vector<int>> recs;
        while(cnt--){
            getline(testcase, input);
            stringstream sss(input);
            int x1, y1, x2, y2;
            char c;
            sss >> c >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c;
            recs.push_back(vector<int>{x1, y1, x2, y2});
        }
        if(sol.checkValidCuts(n, recs)) cout << "T" << endl;
        else cout << "F" << endl;
    }
    testcase.close();
    return 0;
}