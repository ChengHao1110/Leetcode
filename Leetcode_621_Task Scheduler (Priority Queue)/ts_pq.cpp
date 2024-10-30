#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
#include<sstream>
#include <algorithm>

using namespace std;


class Task
{public:
    char name;
    int freq, lastAppear;
    Task(char _name, int _freq, int _lastAppear): name(_name), freq(_freq), lastAppear(_lastAppear){};
    Task(): name('i'), freq(0), lastAppear(INT_MIN){};
};

class cmp{
public:
    bool operator() (Task t1, Task t2){
        return t1.freq < t2.freq;
    }
};

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n) {
        int frequency[26] = {0};
        for(auto c = tasks.begin(); c != tasks.end(); c++) frequency[*c - 'A']++;
        priority_queue<Task, vector<Task>, cmp> task_pq;
        for(int i = 0; i < 26; i++){
            if(frequency[i] != 0) task_pq.push(Task(i + 'A', frequency[i], -n));
        }
        /*
        // check
        while(!task_pq.empty()){
            Task t = task_pq.top();
            cout << t.name << " " << t.freq << endl;
            task_pq.pop();
        }
        cout << endl;
        */
        int current_cycle = 1;
        vector<char> task_order;
        Task t, update;
        vector<Task> saveTask;
        while(!task_pq.empty()){
            t = task_pq.top();
            if(current_cycle - t.lastAppear > n){
                task_order.push_back(t.name);
                task_pq.pop();
                update.name = t.name;
                update.freq = t.freq - 1;
                update.lastAppear = current_cycle;
                if(update.freq > 0){
                    task_pq.push(update);
                }
                current_cycle++;
                if(saveTask.size() > 0){
                    for(auto st = saveTask.begin(); st != saveTask.end(); st++) task_pq.push(*st);
                    saveTask.clear();
                }
            }
            else{
                saveTask.push_back(t);
                task_pq.pop();
                if(task_pq.empty()){
                    task_order.push_back('i');
                    current_cycle++;
                    for(auto st = saveTask.begin(); st != saveTask.end(); st++) task_pq.push(*st);
                    saveTask.clear();
                }
            }
        }
        
        //check
        /*
        for(auto to = task_order.begin(); to != task_order.end(); to++) cout << *to << " ";
        cout << endl;
        */

        return current_cycle - 1;
    }

    int leastInterval_other(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;
        cout << "ch " << chunk << " id " << idel << endl;
        for(int i=24; i>=0; i--){
            if(freq[i] == 0) continue;
            idel -= min(chunk,freq[i]);
            cout << i << " " << idel << endl;
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    Solution sol;
    string data;
    vector<char> tasks;
    int cycle_num = 0;
    while(getline(testcase, data)){
        stringstream ss(data);
        string task;
        while(ss >> task){
            if(task[0] >= 'A' && task[0] <= 'Z') tasks.push_back(task[0]);
            else cycle_num = stoi(task);
        }
        //cout << sol.leastInterval(tasks, cycle_num) << endl;
        cout << sol.leastInterval_other(tasks, cycle_num) << endl;
        tasks.clear();
    }
    return 0;
}