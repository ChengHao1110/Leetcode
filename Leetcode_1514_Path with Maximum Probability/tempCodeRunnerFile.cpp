class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
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