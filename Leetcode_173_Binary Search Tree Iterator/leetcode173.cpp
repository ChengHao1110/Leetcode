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

class BSTIterator {
public:
    vector<int> val;
    int i = 0;
    BSTIterator(TreeNode* root) {
        InorderTravel(root);
    }
    
    void InorderTravel(TreeNode* root){
        if(root->left != nullptr) InorderTravel(root->left);
        val.push_back(root->val);
        if(root->right != nullptr) InorderTravel(root->right);
    }

    int next() {
        int ans = val[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        if(i < val.size()) return true;
        else return false;
    }
};

int main(){

}