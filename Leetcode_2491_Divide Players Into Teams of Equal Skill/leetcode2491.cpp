#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long int sum = 0;
        for(int num : skill) sum += num;
        int target = sum / (skill.size() / 2);
        int left = 0, right = skill.size() - 1;
        sort(skill.begin(), skill.end());
        vector<pair<int, int>> p;
        while(left < right){
            if(skill[left] + skill[right] == target){
                p.push_back({skill[left], skill[right]});
                left++;
                right--;
            }
            else return -1;
        }
        long long int ans = 0;
        for(pair<int, int> pa : p){
            ans += pa.first * pa.second;
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