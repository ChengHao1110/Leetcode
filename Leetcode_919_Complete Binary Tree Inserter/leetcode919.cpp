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

class CBTInserter {
public:
    TreeNode *root;
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(root);
        int parent;
        while(!q.empty()){
            TreeNode* cur = q.front();
            parent = cur->val;
            q.pop();
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            else{
                TreeNode* newLeaf = new TreeNode(val);
                cur->left = newLeaf;
                return parent;
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
            else{
                TreeNode* newLeaf = new TreeNode(val);
                cur->right = newLeaf;
                return parent; 
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    TreeNode *root = new TreeNode(1);
    TreeNode *child = new TreeNode(2);
    root->left = child;

    string input;
    CBTInserter cbt(root);
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}