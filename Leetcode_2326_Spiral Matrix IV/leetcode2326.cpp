#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    const vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int r = 0, c = -1, dir = 0, count = m * n, ver = m - 1, hor = n, times;
        while(count && head != nullptr){
            if(dir % 2 == 0){
                times = hor;
                hor--;
            }
            else{
                times = ver;
                ver--;
            }
            for(int i = 0; i < times; i++){
                r += move[dir].first;
                c += move[dir].second;
                if(head != nullptr){
                    mat[r][c] = head->val;
                    head = head->next;
                }
                else{
                    break;
                }
            }
            count -= times;
            dir++;
            if(dir == 4) dir = 0;
        }
        return mat;
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