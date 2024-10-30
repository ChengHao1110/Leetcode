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
    vector<int> postorderTraversal(TreeNode* root) {
        /* recursive
        vector<int> ans;
        if(root == nullptr) return ans;
        PT(root, ans);
        return ans;
        */

        // iterative
        deque<pair<TreeNode*, bool>> dq;
        vector<int> ans;
        if(root == nullptr) return ans;
        dq.push_front({root, false});
        while(!dq.empty()){
            pair<TreeNode*, bool> cur = dq.front();
            if(cur.second){
                ans.push_back(cur.first->val);
                dq.pop_front();
            }
            else{
                dq.pop_front();
                dq.push_front({cur.first, true});
                if(cur.first->right != nullptr) dq.push_front({cur.first->right, false});
                if(cur.first->left != nullptr) dq.push_front({cur.first->left, false});
            }
        }
        return ans;        
    }

    void PT(TreeNode* root, vector<int> &ans){
        if(root->left != nullptr) PT(root->left, ans);
        if(root->right != nullptr) PT(root->right, ans);
        ans.push_back(root->val); 
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