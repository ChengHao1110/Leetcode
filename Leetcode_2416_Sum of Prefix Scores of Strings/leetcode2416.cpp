#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Trie{
public:
    class Node{
    public:
        int count;
        unordered_map<char, Node*> child;
        Node(){
            count = 0;
            child = unordered_map<char, Node*>();
        }
        Node(int c){
            count = c;
            child = unordered_map<char, Node*>();
        }
    };

    Trie(){
        root = new Node();
    }

    void Insert(string s){
        Node* cur = root;
        for(char ch : s){
            if(cur->child.find(ch) == cur->child.end()){
                Node* node = new Node(1);
                cur->child.insert({ch, node});
            }
            else{
                cur->child[ch]->count++;
            }
            cur = cur->child[ch];
        }
    }

    int Search(string s){
        int prefixCount = 0;
        Node* cur = root;
        for(char ch : s){
            prefixCount += cur->child[ch]->count;
            cur = cur->child[ch];
        }
        return prefixCount;
    }

private:
    Node* root;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(string s : words){
            trie.Insert(s);
        }
        vector<int> ans;
        for(string s : words){
            ans.push_back(trie.Search(s));
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
        stringstream ss(input);
        string s;
        vector<string> sArr;
        while(ss >> s) sArr.push_back(s);
        vector<int> ans = sol.sumPrefixScores(sArr);
        for(int n : ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}