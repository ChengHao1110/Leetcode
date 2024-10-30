#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class People{
    public:
        string name;
        int height;
};

bool cmp(People p1, People p2){
    return p1.height > p2.height;
}

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<People> people;
        vector<string> ans;
        for(int i = 0; i < names.size(); i++){
            People p;
            p.name = names[i];
            p.height = heights[i];
            people.push_back(p);
        }
        sort(people.begin(), people.end(), cmp);
        for(People p : people){
            ans.push_back(p.name);
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
        vector<string> names, ans;
        vector<int> heights;
        stringstream ss(input);
        string name;
        while(ss >> name) names.push_back(name);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        int num;
        while(ss >> num) heights.push_back(num);
        ans = sol.sortPeople(names, heights);
        for(string s : ans) cout << s << " ";
        cout << endl;
    }
    testcase.close();
    return 0;
}