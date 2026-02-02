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
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int ans = 0, maxH = 0;
        unordered_map<int, vector<int>> table;
        q.push({root, 0});
        while(!q.empty()){
            int h = q.front().second;
            TreeNode *n = q.front().first;
            q.pop();

            if(maxH < h){
                // calculate maxH
                ans += minimumSwap(table[maxH]);
                // new height
                table.insert({h, vector<int>()});
                maxH = h;
            }
            table[h].push_back(n->val);
            if(n->left != nullptr) q.push({n->left, h + 1});
            if(n->right != nullptr) q.push({n->right, h + 1});
        }
        ans += minimumSwap(table[maxH]);
        return ans;
    }

    int minimumSwap(vector<int> v){
        int swaps = 0;
        vector<int> sorted_v = v;
        sort(sorted_v.begin(), sorted_v.end());
        cout << sorted_v[0] << endl;
        unordered_map<int, int> eleIdx;
        for(int i = 0; i < v.size(); i++) eleIdx[v[i]] = i;
        for(int i = 0; i < sorted_v.size(); i++){
            if(sorted_v[i] != v[i]){
                swaps++;
                int idx = eleIdx[sorted_v[i]];
                swap(v[i], v[idx]);
                eleIdx[v[i]] = i;
                eleIdx[v[idx]] = idx;
            }
        }
        return swaps;
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