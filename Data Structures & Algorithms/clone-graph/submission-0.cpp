/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, bool> vis;
    unordered_map<Node*, bool> dfsVis;
    unordered_map<Node*, Node*> mp;
    void dfsCopy(Node* node, Node* eq){
        if(dfsVis[node]){
            return;
        }
        dfsVis[node] = true;
        for(auto adj: node->neighbors){
            if(vis[adj]){
                eq->neighbors.push_back(mp[adj]);
            }
            else{
                Node* neighbour = new Node(adj->val);
                eq->neighbors.push_back(neighbour);
                vis[adj] = true;
                mp[adj] = neighbour;
            }
        }
        for(auto adj: node->neighbors){
            dfsCopy(adj, mp[adj]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        Node* start = new Node(1);
        vis[node] = true;
        mp[node] = start;
        dfsCopy(node, start);
        return start;
    }
};
