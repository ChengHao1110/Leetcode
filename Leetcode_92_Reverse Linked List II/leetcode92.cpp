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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode *leftNode = nullptr, *leftleftNode = nullptr, *rightNode = nullptr, *cur = head, *pre = nullptr, *prepre = nullptr;

        for(int i = 0; i < left - 1; i++){
            pre = cur;
            cur = cur->next;
        }

        leftleftNode = pre;
        leftNode = cur;

        prepre = pre;
        pre = cur;
        cur = cur->next;
        for(int i = 0; i < right - left - 1; i++){
            prepre = pre;
            pre = cur;
            cur = cur->next;
            pre->next = prepre;
        }

        rightNode = cur;
        cur = cur->next;
        rightNode->next = pre;
        
        if(left > 1){
            leftleftNode->next = rightNode;
            leftNode->next = cur;
        }
        else{
            head = rightNode;
            leftNode->next = cur;
        }
        
        return head;
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