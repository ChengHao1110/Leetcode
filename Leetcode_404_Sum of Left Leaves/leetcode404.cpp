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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, char>> q;
        q.push(pair(root, 'o'));
        while(!q.empty()){
            pair<TreeNode*, char> cur = q.front();
            q.pop();
            if(!cur.first->left && !cur.first->right && cur.second == 'l') sum += cur.first->val;
            if(cur.first->left) q.push(pair(cur.first->left, 'l'));
            if(cur.first->right) q.push(pair(cur.first->right, 'r'));
            
        }
        return sum;
    }
};

TreeNode* buildTree(vector<string>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    cout << "build tree" << endl;
    TreeNode* root = new TreeNode(stoi(nums[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size() && nums[i] != "null") {
            curr->left = new TreeNode(stoi(nums[i]));
            cout << "add left node " << curr->left->val << endl;
            q.push(curr->left);
        }
        i++;
        if (i < nums.size() && nums[i] != "null") {
            curr->right = new TreeNode(stoi(nums[i]));
            cout << "add right node " << curr->right->val << endl;
            q.push(curr->right);
        }
        i++;
    }
    cout << "end build tree" << endl;
    return root;
}

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        string num;
        vector<string> nums;
        while(ss >> num) nums.push_back(num);
        TreeNode* root = buildTree(nums);
        cout << "Ans: " << sol.sumOfLeftLeaves(root) << endl;
    }
    testcase.close();
    return 0;
}