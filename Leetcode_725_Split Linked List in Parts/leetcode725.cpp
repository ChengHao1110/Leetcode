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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr){
            count++;
            cur = cur->next;
        }
        cur = head;
        int n = count / k, r = count % k;
        vector<ListNode*> ans;
        for(int i = 0; i < k; i++){
            ListNode* partHead = cur;
            int num = n;
            if(r > 0){
                num++;
                r--;
            }
            if(num > 0){
                while(num--){
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = nullptr;
                ans.push_back(partHead);
            }
            else{
                ListNode *node = nullptr;
                ans.push_back(node);
            }
        }
        return ans;
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