#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        int count = 0;
        ListNode *cur = head, *pre = nullptr, *newHead = nullptr;
        while(cur != nullptr){
            count++;
            cur = cur->next;
        }
        int rotateTimes = k % count;
        if(rotateTimes == 0) return head;
        int moveTimes = count - rotateTimes;
        cur = head;
        for(int i = 0; i < moveTimes; i++){
            pre = cur;
            cur = cur->next;
        }
        newHead = cur;
        pre->next = nullptr;
        while(cur != nullptr){
            pre = cur;
            cur = cur->next;
        }
        pre->next = head;
        return newHead;
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