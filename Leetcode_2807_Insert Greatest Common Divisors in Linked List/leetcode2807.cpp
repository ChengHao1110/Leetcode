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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head, *pre = cur;
        while(cur->next != nullptr){
            pre = cur;
            cur = cur->next;
            ListNode *node = new ListNode(GCD(pre->val, cur->val));
            pre->next = node;
            node->next = cur;
        }
        return head;
    }

    int GCD(int a, int b){
        int big = a, small = b;
        if(a < b){
            big = b;
            small = a;
        }
        while(small != 0){
            int temp = big % small;
            big = small;
            small = temp;
        }
        return big;
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