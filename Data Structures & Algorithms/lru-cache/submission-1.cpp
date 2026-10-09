class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    int cap;
    map<int,Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node)
    {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next = nextt;
        nextt->prev=prevv; 
    }

    void insert(Node* node)
    {
        Node* prevv = right->prev;
        prevv->next = node;
        node->prev = prevv;
        node->next =right;
        right->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next=right;
        right->prev =left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node =cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
            remove(cache[key]);
        
        Node* newNode = new Node(key,value);
        cache[key]=newNode;
        insert(newNode);

        if(cache.size()>cap)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
