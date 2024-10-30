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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        bool find = false;
        DFS(root, 0, targetSum, find);
        return find;
    }

    void DFS(TreeNode* n, int sum, int target, bool &find){
        if(find) return;
        sum += n->val;
        if(n->left == nullptr && n->right == nullptr && sum == target){
            find = true;
            return;
        }
        if(n->left != nullptr) DFS(n->left, sum, target, find);
        if(n->right != nullptr) DFS(n->right, sum, target, find);
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