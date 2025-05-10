#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_set>
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

class FindElements {
public:
    unordered_set<int> s;
    
    FindElements(TreeNode* root) {
        s.clear();
        s.insert(0);
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});
        while(!q.empty()){
            int val = q.front().second;
            TreeNode* node = q.front().first;
            q.pop();
            if(node->left != nullptr){
                s.insert(val * 2 + 1);
                q.push({node->left, val * 2 + 1});
            }
            if(node->right != nullptr){
                s.insert(val * 2 + 2);
                q.push({node->right, val * 2 + 2});
            }
        }
    }
    
    bool find(int target) {
        if(s.find(target) != s.end()) return true;
        return false;
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
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}