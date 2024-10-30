#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<deque>

using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        dq = deque<int>();
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(dq.size() == maxSize) return false;
        else{
            dq.push_front(value);
            return true;
        } 
    }
    
    bool insertLast(int value) {
        if(dq.size() == maxSize) return false;
        else{
            dq.push_back(value);
            return true;
        } 
    }
    
    bool deleteFront() {
        if(dq.empty()) return false;
        else{
            deque<int>::iterator iter = dq.begin();
            dq.erase(iter);
            return true;
        } 
    }
    
    bool deleteLast() {
        if(dq.empty()) return false;
        else{
            deque<int>::iterator iter = dq.end();
            dq.erase(iter);
            return true;
        } 
    }
    
    int getFront() {
        if(dq.empty()) return -1;
        else{
            deque<int>::iterator iter = dq.begin();
            return *iter;
        } 
    }
    
    int getRear() {
        if(dq.empty()) return -1;
        else{
            deque<int>::iterator iter = dq.end() - 1;
            return *iter;
        } 
    }
    
    bool isEmpty() {
        if(dq.empty()) return true;
        else return false;
    }
    
    bool isFull() {
        if(dq.size() == maxSize) return true;
        else return false;
    }

private:
    deque<int> dq;
    int maxSize;
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    string input;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}