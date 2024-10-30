#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *cur = head;
        while(cur != nullptr){
            count++;
            cur = cur->next;
        }
        int target = count - n; 
        cur = head;
        ListNode *pre = nullptr;
        //cout << count << " " << target << endl; 
        if(target == 0){
            head = head->next;
            return head;
        }
        for(int i = 0; i < target; i++){
            pre = cur;
            cur = cur->next;
        }
        if(pre != nullptr){
            pre->next = cur->next;
        }
        else return nullptr;
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
        int num;
        vector<int> nums;
        while(ss >> num) nums.push_back(num);
        
        ListNode *head = new ListNode, *cur = new ListNode;
        if(nums.size() > 0){
            head->val = nums[0];
            cur = head;
            for(int i = 1; i < nums.size(); i++){
                ListNode *newNode = new ListNode(nums[i]);
                cur->next = newNode;
                cur = cur->next;
            }
        }
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        ss >> num;
        ListNode *ans = sol.removeNthFromEnd(head, num);

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