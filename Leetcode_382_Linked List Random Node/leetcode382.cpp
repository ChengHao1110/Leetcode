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
    int size = 0;
    ListNode* root;
    Solution(ListNode* head) {
        root = head;
        while(head != nullptr){
            size++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int move = rand() % size;
        ListNode *cur = root;
        while(move--){
            cur = cur->next;
        }
        return cur->val;
    }
};