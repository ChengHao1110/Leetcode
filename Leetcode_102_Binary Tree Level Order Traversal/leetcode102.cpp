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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        vector<int> v;
        int curH = 0;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, h] = q.front();
            q.pop();

            if(h > curH){
                ans.push_back(v);
                v = vector<int>();
                curH = h;
            }

            v.push_back(node->val);
            
            if(node->left != nullptr) q.push({node->left, h + 1});
            if(node->right != nullptr) q.push({node->right, h + 1});
        }

        if(v.size() > 0) ans.push_back(v);

        return ans;
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