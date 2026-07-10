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
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> g2;
        g2[node] = new Node(node->val);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for (Node* nei : cur->neighbors){
                if(g2.find(nei)==g2.end()){
                    g2[nei] = new Node(nei->val);
                    q.push(nei);
                }
                g2[cur]->neighbors.push_back(g2[nei]);
            }
        }
        return g2[node];
    }
};
