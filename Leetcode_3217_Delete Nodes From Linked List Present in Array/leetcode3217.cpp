#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> delSet;
        for(int n : nums) delSet.insert(n);
        ListNode *cur = head, *pre = nullptr;
        while(cur){
            if(delSet.find(cur->val) != delSet.end()){
                if(cur == head){
                    cur = cur->next;
                    head = cur;
                }
                else{
                    cur = cur->next;
                    pre->next = cur;
                }
            }
            else{
                pre = cur;
                cur = cur->next;
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

    }
    testcase.close();
    return 0;
}