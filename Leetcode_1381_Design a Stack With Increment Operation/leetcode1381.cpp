#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class CustomStack {
public:
    CustomStack(int size) {
        st = vector<int>();
        maxSize = size;
        curSize = 0;
    }
    
    void push(int x) {
        if(curSize < maxSize){
            st.push_back(x);
            curSize++;
        }
    }
    
    int pop() {
        if(curSize > 0){
            int temp = st[--curSize];
            st.pop_back();
            return temp;
        }
        else{
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int times = k;
        if(k >= curSize) times = curSize;
        for(int i = 0; i < times; i++) st[i] += val;
    }

private:
    vector<int> st;
    int maxSize, curSize; 
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    testcase.close();
    return 0;
}