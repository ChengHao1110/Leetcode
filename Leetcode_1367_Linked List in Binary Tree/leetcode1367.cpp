#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ListNode *cur = head;
            TreeNode *node = q.front();
            q.pop();
            bool find = false;
            DFS(cur, head, node, find);
            if(find) return true;
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        return false;
    }

    void DFS(ListNode* cur, ListNode* head,TreeNode* root, bool &find){
        if(root->val == cur->val){
            cur = cur->next;
            if(cur == nullptr){
            find = true;
            return;
        } 
        }
        else{
            cur = head;
        }
        if(root->left != nullptr) DFS(cur, head, root->left, find);
        if(root->right != nullptr) DFS(cur, head, root->right, find);
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