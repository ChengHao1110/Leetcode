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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true; 
        ListNode *slow = head->next, *fast = head->next->next, *pre = head, *tmp = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
            tmp->next = pre;
            pre = tmp;
        }
        head->next = nullptr;
        if(fast) slow = slow->next; // over mid center
        while(pre != nullptr && slow != nullptr){
            if(pre->val != slow->val) return false;
            else{
                pre = pre->next;
                slow = slow->next;
            }
        }
        return true;
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
    Solution sol;
    int i = 1;
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
        cout << "idx: " << i << endl;
        bool ans = sol.isPalindrome(list);
        cout <<  "ans: " <<  ans << endl;
        i++;
    }
    return 0;
}