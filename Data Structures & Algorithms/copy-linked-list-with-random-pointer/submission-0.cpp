/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*,Node*> lmap{{nullptr,nullptr}};

       Node* cur = head;
       while(cur != nullptr)
       {
        if(lmap.find(cur) == lmap.end())
            lmap[cur] = new Node(0);
        lmap[cur]->val = cur->val;
        if(lmap.find(cur->next) == lmap.end())
            lmap[cur->next] = new Node(0);
        lmap[cur]->next = lmap[cur->next];
        if(lmap.find(cur->random) == lmap.end())
            lmap[cur->random] = new Node(0);
        lmap[cur]->random = lmap[cur->random];

        cur=cur->next;
       } 
       return lmap[head];

    }
};
