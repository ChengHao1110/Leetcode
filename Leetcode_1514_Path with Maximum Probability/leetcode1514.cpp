#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<cmath>
#include<cfloat>

using namespace std;

class Node{
    public:
    int id, preNodeId;
    vector<pair<int, double>> adjNodeList;
    bool visited;
    double cost;

    Node(int id){
        this->id = id;
        preNodeId = -1;
        adjNodeList.clear();
        visited = false;
        cost = -DBL_MAX;
    }
};

class Compare{
    public:
    bool operator()(Node n1, Node n2){
        return n1.cost < n2.cost;
    };
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // initial
        vector<double> prob(n, 0);
        vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());
        // connect edge
        for(int i = 0 ; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        // no edge to end_node
        if(adj[end_node].size() == 0) return 0;
        // set start
        prob[start_node] = 1;

        // compute
        int id, movetoId;
        double p, nextP;
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({prob[start_node], start_node});
        while(!pq.empty()){
            pair<double, int> curNode = pq.top();
            pq.pop();

            id = curNode.second;
            p = curNode.first;
            
            // compute adj node
            for(int i = 0; i < adj[id].size(); i++){
                pair<int, double> edge = adj[id][i];
                movetoId = edge.first;
                nextP = edge.second;
                double newCost = p * nextP;
                if(newCost > prob[movetoId]){
                    prob[movetoId] = newCost;
                    pq.push({prob[movetoId], movetoId});
                }
            }
        }
        return prob[end_node];
    }

    double maxProbability_old(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // initial
        vector<Node> nodes;
        for(int i = 0; i < n; i++){
            Node node(i);
            nodes.push_back(node);
        }
        // connect edge
        for(int i = 0 ; i < edges.size(); i++){
            nodes[edges[i][0]].adjNodeList.push_back({edges[i][1], succProb[i]});
            nodes[edges[i][1]].adjNodeList.push_back({edges[i][0], succProb[i]});
        }
        // no edge to end_node
        if(nodes[end_node].adjNodeList.size() == 0) return 0;
        // set start
        nodes[start_node].cost = 1;

        // compute
        priority_queue<Node, vector<Node>, Compare> pq;
        pq.push(nodes[start_node]);
        while(!pq.empty()){
            Node curNode = pq.top();
            pq.pop();
            // isVisited
            int id = curNode.id;
            nodes[id].visited = true;
            
            // compute adj node
            for(int i = 0; i < nodes[id].adjNodeList.size(); i++){
                pair<int, double> edge = nodes[id].adjNodeList[i]; // first: id, second: cost;
                if(nodes[edge.first].visited) continue; 
                double newCost = nodes[id].cost * edge.second;
                if(newCost > nodes[edge.first].cost){
                    nodes[edge.first].cost = newCost;
                    nodes[edge.first].preNodeId = id;
                }
                pq.push(nodes[edge.first]);
                
            }
            if(id == end_node) break;
        }
        if(nodes[end_node].cost == -DBL_MAX) return 0;
        return nodes[end_node].cost;
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
        int nodeCnt, edgeCnt, start, end;
        ss >> nodeCnt >> edgeCnt >> start >> end;
        vector<vector<int>> edges;
        vector<double> succProb;
        int p1, p2;
        double prob;
        ss.clear();
        ss.str("");
        for(int i = 0; i < edgeCnt; i++){
            getline(testcase, input);
            ss << input;
            ss >> p1 >> p2 >> prob;
            vector<int> edge;
            edge.push_back(p1);
            edge.push_back(p2);
            edges.push_back(edge);
            succProb.push_back(prob);
            ss.clear();
            ss.str("");
        }
        cout << sol.maxProbability(nodeCnt, edges, succProb, start, end) << endl;
    } 
    testcase.close();
    return 0;
}