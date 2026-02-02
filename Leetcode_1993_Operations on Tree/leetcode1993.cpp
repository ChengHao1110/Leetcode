#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class LockingTree {
public:
    int n;
    vector<int> parent;
    vector<vector<int>> children;
    vector<pair<bool, int>> locked;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        locked.resize(n, {false, -1});
        children.resize(n, vector<int>());
        this->parent = parent;
        for(int i = 1; i < parent.size(); i++){
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(!locked[num].first){
            locked[num].first = !locked[num].first;
            locked[num].second = user;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool unlock(int num, int user) {
        if(locked[num].first && locked[num].second == user){
            locked[num].first = !locked[num].first;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool upgrade(int num, int user) {
        if(!FindParentLocked(num)){
            bool childLocked = false;
            queue<int> q;
            q.push(num);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int i = 0; i < children[cur].size(); i++){
                    int childId = children[cur][i];
                    if(locked[childId].first){
                        childLocked = true;
                        locked[childId].first = !locked[childId].first;
                    }
                    q.push(childId);
                }
            }
            if(childLocked){
                locked[num].first = true;
                locked[num].second = user;
            }
            return childLocked;
        }
        else{
            return false;
        }
    }

    bool FindParentLocked(int num){
        if(num == -1) return false;
        if(locked[num].first) return true;
        return FindParentLocked(parent[num]);
    }
};