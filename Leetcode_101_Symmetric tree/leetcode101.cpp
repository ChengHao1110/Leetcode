#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;


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
    bool isSymmetric(TreeNode* root) {
        /*
        //DFS
        if(root->left == nullptr && root->right == nullptr) return true;
        bool same = true;
        DFS(root->left, root->right, same);
        return same;
        */
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->left == nullptr || root->right == nullptr) return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *n1 = q.front();
            q.pop();
            TreeNode *n2 = q.front();
            q.pop();
            if(n1 == nullptr && n2 == nullptr) continue;
            if(n1 == nullptr || n2 == nullptr) return false;
            if(n1->val == n2->val){
                q.push(n1->left);
                q.push(n2->right);
                q.push(n1->right);
                q.push(n2->left);
            }
            else{
                return false;
            }
        }
        return true;
    }

    void DFS(TreeNode* n1, TreeNode *n2, bool &same){
        if(n1 != nullptr && n2 != nullptr){
            if(n1->val == n2->val){
                DFS(n1->left, n2->right, same);
                DFS(n1->right, n2->left, same);
            }
            else{
                same = false;
                return;
            }
        }
        else if(n1 == nullptr && n2 == nullptr){
            return;
        }
        else{
            same = false;
            return;
        }

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