#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
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
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            unordered_map<TreeNode*, TreeNode*> parent;
            int maxHeight = 0;
            queue<pair<TreeNode*, int>> q;
            priority_queue< pair<int, TreeNode*>, vector<pair<int, TreeNode*>> > pq;
            q.push({root, 0});
            pq.push({0, root});
            while(!q.empty()){
                TreeNode* cur = q.front().first;
                int height = q.front().second;
                q.pop();
                maxHeight = max(maxHeight, height);
                if(cur->left != nullptr){
                    parent.insert({cur->left, cur});
                    q.push({cur->left, height + 1});
                    pq.push({height + 1, cur->left});
                }
                if(cur->right != nullptr){
                    parent.insert({cur->right, cur});
                    q.push({cur->right, height + 1});
                    pq.push({height + 1, cur->right});
                }
            }
    
            vector<TreeNode*> maxDepthNodes;
            while(!pq.empty()){
                if(pq.top().first == maxHeight){
                    maxDepthNodes.push_back(pq.top().second);
                    pq.pop();
                }
                else{
                    break;
                }
            }
            int val = INT_MAX;
            TreeNode *ans;
            if(maxDepthNodes.size() == 1) return maxDepthNodes[0];
            for(int i = 0; i < maxDepthNodes.size(); i++){
                for(int j = i + 1; j < maxDepthNodes.size(); j++){
                    TreeNode *a = maxDepthNodes[i], *b = maxDepthNodes[j];
                    while(parent[a] != parent[b]){
                        a = parent[a];
                        b = parent[b];
                    }
                    if(parent[a]->val < val){
                        val = parent[a]->val;
                        ans = parent[a];
                    }
                }
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