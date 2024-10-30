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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *cur = list1;
        ListNode *head, *tail;
        int times = 0;
        while(cur != nullptr){
            //cout << cur->val << endl;
            if(times == a - 1){
                head = cur;
            }
            if(times == b + 1){
                tail = cur;
                break;
            } 
            cur = cur->next;
            times++;
        }
        head->next = list2;

        cur = list2;
        while(cur->next != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cur->next = tail;

        return list1;
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
        int idx1, idx2;
        ListNode *list1, *list2;
        vector<int> arr1, arr2;
        bool isListTwo = false;
        while(ss >> num){
            if(num == "a"){
                ss >> num;
                idx1 = stoi(num);
                continue;
            }
            if(num == "b"){
                ss >> num;
                idx2 = stoi(num);
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
        ListNode *newList = sol.mergeInBetween(list1, idx1, idx2, list2);
        cur = newList;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }        
    }

    return 0;
}