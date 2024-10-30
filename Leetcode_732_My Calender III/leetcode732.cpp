#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {
        event = map<int, int>();
    }
    
    int book(int startTime, int endTime) {
        event[startTime]++;
        event[endTime]--;
        int maxK = 0, count = 0;
        for(pair<int, int> p : event){
            count += p.second;
            maxK = max(maxK, count);
        }
        return maxK;
    }

private:
    map<int, int> event;
};


int main(){

    return 0;
}