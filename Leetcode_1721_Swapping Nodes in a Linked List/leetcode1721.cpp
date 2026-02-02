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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode *cur = head;
        while(cur != nullptr){
            arr.push_back(cur->val);
            cur = cur->next;
        }

        int size = arr.size(), temp = arr[k - 1], i = 0;
        arr[k - 1] = arr[size - k];
        arr[size - k] = temp;
        
        cur = head;
        while(cur != nullptr){
            cur->val = arr[i];
            i++;
            cur = cur->next;
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