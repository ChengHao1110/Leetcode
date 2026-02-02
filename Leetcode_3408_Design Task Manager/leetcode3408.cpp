#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<set>

using namespace std;

class TaskManager {
public:
    unordered_map<int, pair<int, int>> tasksTable; // {taskId, {priority, userId}}
    set<pair<int, pair<int, int>>> tasksPriority; // {-priority, {-taskId, userId}}

    TaskManager(vector<vector<int>>& tasks) {
        for(auto t : tasks){
            tasksTable[t[1]] = {t[2], t[0]};
            tasksPriority.insert({-t[2], {-t[1], t[0]}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasksTable[taskId] = {priority, userId};
        tasksPriority.insert({-priority, {-taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        auto [oriP, oriU] = tasksTable[taskId];
        tasksPriority.erase({-oriP, {-taskId, oriU}});
        tasksTable[taskId].first = newPriority;
        tasksPriority.insert({-newPriority, {-taskId, oriU}});
    }
    
    void rmv(int taskId) {
        auto [oriP, oriU] = tasksTable[taskId];
        tasksTable.erase(taskId);
        tasksPriority.erase({-oriP, {-taskId, oriU}});
    }
    
    int execTop() {
        if(tasksPriority.empty()) return -1;
        auto info = *tasksPriority.begin();
        int user = info.second.second;
        rmv(-info.second.first);
        return user;
    }
};


int main(){

    return 0;
}