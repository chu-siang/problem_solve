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
    Node* dfs(Node*cur, unordered_map<Node*,Node*>&mp){
        Node *clone = new Node(cur->val);
        vector<Node*>neighbor;
        mp[cur] = clone;
        for(auto i : cur->neighbors){
            if(mp.find(i) != mp.end()){
                neighbor.push_back(mp[i]);
            }else{
                neighbor.push_back(dfs(i,mp));
            }
        }
        clone->neighbors=neighbor;
        return clone;

    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        if(node == nullptr)return nullptr;
        if(node->neighbors.size() == 0){
            Node* nd = new Node(node->val);
            return nd;
        }
        return dfs(node,mp);
    }
};


"
class Solution {
public:
    
    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) {
        visited[node->val] = clone_node;
        
        for(Node* x : node->neighbors) {
            if(visited[x->val] == NULL) {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            } else {
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        
        Node* clone_node = new Node(node->val);
        
      
        
        vector<Node*> visited(101, NULL); 
        visited[node->val] = clone_node;
        

        DFS(node, clone_node, visited);
 
        
        
        return clone_node;
    }
};
"