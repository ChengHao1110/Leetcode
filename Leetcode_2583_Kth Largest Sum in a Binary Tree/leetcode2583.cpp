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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int curLevel = 1;
        queue<pair<int, TreeNode*>> q;
        priority_queue<long long, vector<long long>> pq;
        q.push({1, root});

        long long levelSum = 0;
        while(!q.empty()){
            pair<int, TreeNode*> cur = q.front();
            q.pop();
            if(cur.first == curLevel){
                levelSum += cur.second->val;
            }
            else{
                // add to pq
                pq.push(levelSum);
                // reset
                levelSum = cur.second->val;
                curLevel = cur.first;
            }
            if(cur.second->left != nullptr) q.push({cur.first + 1, cur.second->left});
            if(cur.second->right != nullptr) q.push({cur.first + 1, cur.second->right});
        }
        // add last level
        pq.push(levelSum);
        if(k > pq.size()) return -1;
        k--;
        while(k--){
            if(!pq.empty()) pq.pop();
        }
        return pq.top();
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