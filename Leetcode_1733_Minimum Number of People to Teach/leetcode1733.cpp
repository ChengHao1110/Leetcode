#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> need;
        for(auto f : friendships){
            int u = f[0] - 1, v = f[1] - 1;
            bool communicated = false;
            for(auto lu : languages[u]){
                for(auto lv : languages[v]){
                    if(lu == lv){
                        communicated = true;
                        break;
                    }
                }
            }
            if(!communicated){
                need.insert(u);
                need.insert(v);
            }
        }

        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            int teach = 0;
            for(auto p : need){
                bool needTeach = true;
                for(auto lp : languages[p]){
                    if(lp == i){
                        needTeach = false;
                        break;
                    } 
                }
                if(needTeach) teach++;
            }
            ans = min(ans, teach);
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