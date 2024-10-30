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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        bool turn1 = true; 
        ListNode *cur1 = list1, *cur2 = list2, *head, *pre1 = nullptr, *pre2 = nullptr;
        if(cur1->val <= cur2->val){
            head = list1;
        }
        else{
            head = list2;
            turn1 = false;
        }

        while(cur1 != nullptr && cur2 != nullptr){
            //cout << "turn: " << turn1 << endl;
            //true move cur1, false move cur2
            if(turn1){
                while(cur1 != nullptr && cur1->val <= cur2->val){
                    //cout << "cmp: 1-> " << cur1->val << " 2-> " << cur2->val << endl;
                    pre1 = cur1;
                    cur1 = cur1->next;
                }
                //cout << "cur1 val: " << cur1->val << endl;
                pre1->next = cur2;
                turn1 = false;
            }
            else{
                while(cur2 != nullptr && cur2->val <= cur1->val){
                    //cout << "cmp: 1-> " << cur1->val << " 2-> " << cur2->val << endl;
                    pre2 = cur2;
                    cur2 = cur2->next;
                }
                //cout << "cur2 val: " << cur2->val << endl;
                pre2->next = cur1;
                turn1 = true;
            }
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
        stringstream ss(input);
        vector<int> nums;
        int num;

        //list 1
        while(ss >> num) nums.push_back(num); 
        ListNode *list1 = nullptr, *cur;
        if(nums.size() > 0){
            list1 = new ListNode();
            list1->val = nums[0];
            cur = list1;
            for(int i = 1; i < nums.size(); i++){
                ListNode *node = new ListNode(nums[i]);
                cur->next = node;
                cur = node;
            }   
        }
        nums.clear();
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;

        //list 2
        while(ss >> num) nums.push_back(num);
        ListNode *list2 = nullptr;
        if(nums.size() > 0){
            list2 = new ListNode();
            list2->val = nums[0];
            cur = list2;
            for(int i = 1; i < nums.size(); i++){
                ListNode *node = new ListNode(nums[i]);
                cur->next = node;
                cur = node;
            }   
        }

        ListNode *ans = sol.mergeTwoLists(list1, list2);
        cur = ans;
        while(cur != nullptr){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    testcase.close();
    return 0;
}