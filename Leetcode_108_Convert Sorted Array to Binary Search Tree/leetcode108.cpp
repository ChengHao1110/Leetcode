#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

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
    vector<int> arr;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        arr = nums;
        TreeNode *root = Generate(0, arr.size() - 1);
        return root;
    }

    TreeNode* Generate(int low, int high){
        if(low > high) return nullptr;
        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = Generate(low, mid - 1);
        node->right = Generate(mid + 1, high);
        return node;
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