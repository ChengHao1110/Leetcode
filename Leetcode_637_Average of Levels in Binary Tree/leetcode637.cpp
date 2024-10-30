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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long long int, int>> levelSum;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if(levelSum.size() == cur.second){
                levelSum.emplace_back(pair<int , int>{cur.first->val, 1});
            }
            else{
                levelSum[cur.second].first += cur.first->val;
                levelSum[cur.second].second++;
            }
            if(cur.first->left != nullptr) q.push({cur.first->left, cur.second + 1});
            if(cur.first->right != nullptr) q.push({cur.first->right, cur.second + 1});
        }
        vector<double> ans;
        for(int i = 0; i < levelSum.size(); i++){
            ans.push_back(levelSum[i].first / (double)levelSum[i].second);
        }
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