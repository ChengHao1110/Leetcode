#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:    
    void deleteNode(ListNode* node) {
        ListNode *cur = node, *prev = nullptr;
        while(cur->next != nullptr){
            cur->val = cur->next->val;
            if(cur->next->next == nullptr){
                cur->next = nullptr;
            }
            else{
                cur = cur->next;
            }
        }
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
    Solution sol;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}