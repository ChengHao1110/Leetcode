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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1, *c2 = l2, *newList = new ListNode;
        // do first
        int value = c1->val + c2->val;
        bool isCarry = false;
        if(value >= 10){
            value %= 10;
            isCarry = true;
        }
        newList->val = value;
        c1 = c1->next;
        c2 = c2->next;
        ListNode *cur = newList;
        while(c1 != nullptr && c2 != nullptr){
            value = (isCarry) ? c1->val + c2->val + 1 : c1->val + c2->val;
            if(value >= 10){
                value %= 10;
                isCarry = true;
            }
            else isCarry = false;
            ListNode *newNode = new ListNode;
            newNode->val = value;
            cur->next = newNode;
            c1 = c1->next;
            c2 = c2->next;
            cur = cur->next;
        }
        if(c1 == nullptr && c2 != nullptr){ // digitNum : l2 > l1
            while(c2 != nullptr){
                value = (isCarry) ? c2->val + 1 : c2->val;
                if(value >= 10){
                    value %= 10;
                    isCarry = true;
                }
                else isCarry = false;
                ListNode *newNode = new ListNode;
                newNode->val = value;
                cur->next = newNode;
                c2 = c2->next;
                cur = cur->next;
            }
        }
        else if(c1 != nullptr && c2 == nullptr){
            while(c1 != nullptr){
                value = (isCarry) ? c1->val + 1 : c1->val;
                if(value >= 10){
                    value %= 10;
                    isCarry = true;
                }
                else isCarry = false;
                ListNode *newNode = new ListNode;
                newNode->val = value;
                cur->next = newNode;
                c1 = c1->next;
                cur = cur->next;
            }
        }
        if(isCarry){
            ListNode *newNode = new ListNode;
            newNode->val = 1;
            cur->next = newNode;
        }
        return newList;
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
        ListNode *list1, *list2;
        vector<int> arr1, arr2;
        bool isListTwo = false;
        while(ss >> num){
            if(num == "a"){
                isListTwo = true;
                continue;
            }
            if(!isListTwo){
                arr1.push_back(stoi(num));
            }
            else{
                arr2.push_back(stoi(num));
            }
        }

        //for(auto n: arr1) cout << n << " "; cout << endl;

        // arr1 -> list1
        list1 = new ListNode;
        list1->val = arr1[0];
        ListNode *cur = list1;
        for(int i = 1; i < arr1.size(); i++){
            ListNode *newNode = new ListNode(arr1[i]);
            cur->next = newNode;
            cur = cur->next;
        }

        // arr2 -> list2
        list2 = new ListNode;
        list2->val = arr2[0];
        cur = list2;
        for(int i = 1; i < arr2.size(); i++){
            ListNode *newNode = new ListNode(arr2[i]);
            cur->next = newNode;
            cur = cur->next;
        }

        Solution sol;
        ListNode *newList = sol.addTwoNumbers(list1, list2);
        cur = newList;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;        
    }

    return 0;
}