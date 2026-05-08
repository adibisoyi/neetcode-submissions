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
        unordered_map<Node*,Node*> newlist;
        queue<Node*> q;
        newlist[node] = new Node(node->val);
        q.push(node);

        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for(auto nghbor : cur->neighbors)
            {
                if(newlist.find(nghbor)==newlist.end())
                {
                    newlist[nghbor] = new Node(nghbor->val);
                    q.push(nghbor);
                }
                newlist[cur]->neighbors.push_back(newlist[nghbor]);
            }
        }
        return newlist[node];
    }
};
