#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        int curMaxDepth = 0;
        DFS(root, 0, curMaxDepth, ans);
        return ans;
    }

    void DFS(TreeNode* n, int depth, int &curMaxDepth, vector<int> &ans){
        if(depth == curMaxDepth){
            ans.push_back(n->val);
            curMaxDepth++;
        }
        if(n->right != nullptr) DFS(n->right, depth + 1, curMaxDepth, ans);
        if(n->left != nullptr) DFS(n->left, depth + 1, curMaxDepth, ans);
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