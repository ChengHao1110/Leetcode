#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
#include<queue>

using namespace std;

class Course{
public:
    int degree;
    vector<int> next;
    unordered_set<int> from;
    Course(){
        degree = 0;
        next = vector<int>();
        from = unordered_set<int>();
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        
        vector<Course> courses(numCourses);
        for(int i = 0; i < numCourses; i++){
            courses[i] = Course();
            courses[i].from.insert(i);
        }

        //create graph
        for(int i = 0; i < prerequisites.size(); i++){
            courses[prerequisites[i][0]].next.push_back(prerequisites[i][1]);
            courses[prerequisites[i][1]].degree++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(courses[i].degree == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < courses[cur].next.size(); i++){
                int nextId = courses[cur].next[i];
                unordered_set<int> newSet;
                set_union(courses[cur].from.begin(), courses[cur].from.end(), courses[nextId].from.begin(), courses[nextId].from.end(), inserter(newSet, newSet.begin()));
                courses[nextId].from = newSet;
                if(--courses[nextId].degree == 0){
                    q.push(nextId);
                }
            }
        }

        for(int i = 0; i < numCourses; i++){
            for(auto s : courses[i].from){
                isReachable[s][i] = true;
            }
        }

        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(isReachable[queries[i][0]][queries[i][1]]);
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