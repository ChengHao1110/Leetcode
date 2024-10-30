#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
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
    vector<int> height, removal;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height.resize(100001, -1);
        removal.resize(100001, -1);

        dfs(root, 0, 0);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(removal[queries[i]]);
        }
        return ans;
    }

    int ComputeHeight(TreeNode *root){
        if(root == nullptr) return -1;
        int idx = root->val;
        // already computed
        if(height[idx] != -1) return height[idx];
        // not computed
        height[idx] = 1 + max(ComputeHeight(root->left), ComputeHeight(root->right));
        return height[idx];
    }

    void dfs(TreeNode *root, int curLevel, int maxLevel){
        if(root == nullptr) return;
        int idx = root->val;
        removal[idx] = maxLevel;
        dfs(root->left, curLevel + 1, max(maxLevel, 1 + curLevel + ComputeHeight(root->right)));
        dfs(root->right, curLevel + 1, max(maxLevel, 1 + curLevel + ComputeHeight(root->left)));
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