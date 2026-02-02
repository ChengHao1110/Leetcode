#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        pq = priority_queue<int, vector<int>, greater<int>>();
        for(int i = 1; i <= n; i++) pq.push(i);
    }
    
    int reserve() {
        int r = pq.top();
        pq.pop();
        return r;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


int main(){
    return 0;
}