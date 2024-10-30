#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;


// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *cur = head, *pre = nullptr, *next = head->next;

        while(next != nullptr){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        head = cur; 

        return head;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string data;
    while(getline(testcase, data)){
        stringstream ss(data);
        string num;
        vector<int> arr1;
        while(ss >> num){
            arr1.push_back(stoi(num));
        }

        //for(auto n: arr1) cout << n << " "; cout << endl;

        // arr1 -> list
        ListNode *list = new ListNode, *cur = new ListNode;
        if(arr1.size() > 0){
            list->val = arr1[0];
            cur = list;
            for(int i = 1; i < arr1.size(); i++){
                ListNode *newNode = new ListNode(arr1[i]);
                cur->next = newNode;
                cur = cur->next;
            }
        }

        Solution sol;
        ListNode *newList = sol.reverseList(list);
        cur = newList;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;     
    }

    return 0;
}