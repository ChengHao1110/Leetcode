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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *pre = head, *cur = head->next, *next;
        if(cur != nullptr) head = cur;
        while(cur != nullptr){
            next = cur->next;
            if(next == nullptr){
                // end
                cur->next = pre;
                pre->next = next;
                cur = nullptr;
            }
            else{
                cur->next = pre;
                if(next->next != nullptr){
                    //even
                    pre->next = next->next;
                    pre = next;
                    cur = next->next;
                }
                else{
                    //old
                    pre->next = next;
                    cur = nullptr;
                }             
            }
            // check
            /*
            cout << "Print List" << endl;
            ListNode *curHead = head;
            while(curHead != nullptr){
                cout << curHead->val << " ";
                curHead = curHead->next;   
            }
            cout << endl;
            */
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
        vector<int> nums;
        stringstream ss(input);
        int num;
        while(ss >> num) nums.push_back(num);
        ListNode *list = nullptr, *cur, *ans;
        if(nums.size() > 0){
            list = new ListNode(nums[0]);
            cur = list;
            for(int i = 1; i < nums.size(); i++){
                ListNode *node = new ListNode(nums[i]);
                cur->next = node;
                cur = node;
            }
        }
        ans = sol.swapPairs(list);
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