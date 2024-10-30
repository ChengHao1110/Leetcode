#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        event = map<int, int>();
    }
    
    bool book(int start, int end) {
        event[start]++;
        event[end]--;
        int count = 0;
        for(map<int, int>::iterator iter = event.begin(); iter != event.end(); iter++){
            count += iter->second;
            if(count > 2){
                event[start]--;
                event[end]++;
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> event;
};


int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    string input;
    MyCalendarTwo myCalendar;
    while(getline(testcase, input)){
        stringstream ss(input);
        int s, e;
        while(ss >> s >> e){
            cout << "book(" << s << "," << e << "): "; 
            if(myCalendar.book(s, e)) cout << "T" << endl;
            else cout << "F" << endl;
        }
    }
    testcase.close();
    return 0;
}