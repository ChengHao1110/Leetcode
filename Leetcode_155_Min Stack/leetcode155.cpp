#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class MinStack {
public:
    public:
        stack<int> dataSt, minSt;

    MinStack() {

    }
    
    void push(int val) {
        dataSt.push(val);
        if(minSt.empty()){
            minSt.push(val);
        }
        else{
            int t = minSt.top();
            if(val > t) minSt.push(t);
            else minSt.push(val);
        }
    }
    
    void pop() {
        dataSt.pop();
        minSt.pop();
    }
    
    int top() {
        return dataSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    testcase.close();
    return 0;
}