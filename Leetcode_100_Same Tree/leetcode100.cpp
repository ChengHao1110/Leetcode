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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if ( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) return false;

        queue<TreeNode*> qp, qq;
        qp.push(p);
        qq.push(q);

        while(!qp.empty() && !qq.empty()){
            TreeNode* curP = qp.front();
            qp.pop();
            TreeNode* curQ = qq.front();
            qq.pop();
            if(curP->val != curQ->val) return false;
            if( (curP->left != nullptr && curQ->left == nullptr) || (curP->left == nullptr && curQ->left != nullptr)) return false;
            if(curP->left != nullptr){
                qp.push(curP->left);
                qq.push(curQ->left);
            }
            if( (curP->right != nullptr && curQ->right == nullptr) || (curP->right == nullptr && curQ->right != nullptr)) return false;
            if(curP->right != nullptr){
                qp.push(curP->right);
                qq.push(curQ->right);
            }
        }

        return true;
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