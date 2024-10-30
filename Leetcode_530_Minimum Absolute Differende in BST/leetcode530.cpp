#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        vector<int> element;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            element.push_back(cur->val);
            q.pop();
            if(cur->left != nullptr){
                for(int n : element) diff = min(diff, abs(n - cur->left->val));
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                for(int n : element) diff = min(diff, abs(n - cur->right->val));
                q.push(cur->right);
            }
        }
        return diff;
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