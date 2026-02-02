#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

class  Node{
public:
    int index;
    vector<int> freq; // record max aplhabet freq of each path
};

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length(), cnt = 0, maxValue = -1, end;
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n, vector<int>{});
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            degree[edges[i][1]]++;
        }

        vector<Node> node(n);
        for(int i =0; i < n; i++){
            node[i].index = i;
            node[i].freq.resize(26, 0);
        }

        queue<Node> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                node[i].freq[colors[i] - 'a']++;
                q.push(node[i]);
            }
        }
        
        while(!q.empty()){
            int curNode = q.front().index;
            vector<int> freq = q.front().freq;
            cnt++;
            q.pop();
            if(graph[curNode].size() == 0){
                maxValue = max(maxValue, *max_element(freq.begin(), freq.end()));
            }
            else{
                for(int i = 0; i < graph[curNode].size(); i++){
                    end = graph[curNode][i];

                    for(int j = 0; j < 26; j++){
                        int val = node[curNode].freq[j] + (colors[end] - 'a' == j ? 1 : 0);
                        node[end].freq[j] = max(node[end].freq[j], val);
                    }

                    if(--degree[end] == 0){
                        q.push(node[end]);
                    }
                }
            }
        }

        if(cnt != n) return -1; // cycle detected
        return maxValue;
    }
};

/*
class  Node{
public:
    int index;
    vector<int> freq;
    Node(){
        index = 0;
        freq.resize(26, 0);
    }
};

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length(), cnt = 0, maxValue = -1;
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n, vector<int>{});
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            degree[edges[i][1]]++;
        }

        queue<Node> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                Node node;
                node.index = i;
                node.freq[colors[i] - 'a']++;
                q.push(node);
            }
        }
        
        while(!q.empty()){
            int curNode = q.front().index;
            vector<int> freq = q.front().freq;
            cnt++;
            cout << "curNode " << curNode << endl;
            q.pop();
            if(graph[curNode].size() == 0){
                maxValue = max(maxValue, *max_element(freq.begin(), freq.end()));
            }
            else{
                for(int i = 0; i < graph[curNode].size(); i++){
                    if(--degree[graph[curNode][i]] == 0){
                        Node node;
                        node.index = graph[curNode][i];
                        node.freq = freq;
                        node.freq[colors[graph[curNode][i]] - 'a']++;
                        q.push(node);
                    }
                }
            }
            
            for(int i = 0; i < 26; i++){
                char ch = 'a' + i;
                cout << ch << freq[i] << " ";
            }
            cout << endl;
            
        }

        if(cnt != n) return -1; // cycle detected
        return maxValue;
    }
};
*/


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