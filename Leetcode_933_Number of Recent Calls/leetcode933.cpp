#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class RecentCounter {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    RecentCounter() {
        pq = priority_queue<int, vector<int>, greater<int>>();
    }
    
    int ping(int t) {
        if(pq.empty()){
            pq.push(t);
            return 1;
        }
        else{
            pq.push(t);
            int threshold = t - 3000;
            while(pq.top() < threshold){
                pq.pop();
            }
            return pq.size();
        }
    }
};

int main(){

    return 0;
}