#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        while(!q.empty()) q.pop();
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int val = q.back(), size = q.size();
        queue<int> newQueue;
        size--;
        while(size--){
            newQueue.push(q.front());
            q.pop();
        }
        q.swap(newQueue);
        return val;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
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
    MyStack myStack;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<string> ops;
        string op;
        while(ss >> op) ops.push_back(op);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        int num;
        vector<int> nums;
        while(ss >> num) nums.push_back(num);
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "push"){
                myStack.push(nums[i]);
            }
            else if(ops[i] == "top"){
                cout << myStack.top() << endl;
            }
            else if(ops[i] == "pop"){
                cout << myStack.pop() << endl;
            }
            else{
                if(myStack.empty()) cout << "true" << endl;
                else cout << "false" << endl;
            }
        }
    }
    testcase.close();
    return 0;
}