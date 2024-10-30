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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSums;
        vector<vector<pair<TreeNode*, TreeNode*>>> levelNodes;
        vector<pair<TreeNode*, TreeNode*>> Nodes;
        queue<pair<int, pair<TreeNode*, TreeNode*>>> q;

        root->val = 0;
        int curLevel = 1, levelSum = 0;
        q.push({1, {root, nullptr}});
        while(!q.empty()){
            pair<int, pair<TreeNode*, TreeNode*>> curNode = q.front();
            q.pop();

            if(curNode.first == curLevel){
                Nodes.push_back({curNode.second.first, curNode.second.second});
                levelSum += curNode.second.first->val;
            }
            else{
                levelNodes.push_back(Nodes);
                levelSums.push_back(levelSum);

                Nodes = vector<pair<TreeNode*, TreeNode*>>{{curNode.second.first, curNode.second.second}};
                levelSum = curNode.second.first->val;
                curLevel = curNode.first;
            }

            if(curNode.second.first->left != nullptr) q.push({curNode.first + 1, {curNode.second.first->left, curNode.second.first}});
            if(curNode.second.first->right != nullptr) q.push({curNode.first + 1, {curNode.second.first->right, curNode.second.first}});
        }
        levelNodes.push_back(Nodes);
        levelSums.push_back(levelSum);

        for(int i = 1; i < levelNodes.size(); i++){
            TreeNode* parent = nullptr;
            for(int j = 0; j < levelNodes[i].size(); j++){
                if(levelNodes[i][j].second != parent){
                    parent = levelNodes[i][j].second;
                    int childSum = 0;
                    if(levelNodes[i][j].second->left != nullptr) childSum += levelNodes[i][j].second->left->val;
                    if(levelNodes[i][j].second->right != nullptr) childSum += levelNodes[i][j].second->right->val;
                    if(levelNodes[i][j].second->left != nullptr) levelNodes[i][j].second->left->val = levelSums[i] - childSum;
                    if(levelNodes[i][j].second->right != nullptr) levelNodes[i][j].second->right->val = levelSums[i] - childSum;
                }
            }
        }

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

    string input;
    Solution sol;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}