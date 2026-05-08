class TrieNode{
public:
    unordered_map<char,TrieNode*> node;
    bool eow=false;
};
class PrefixTree {
    private:
        TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c:word)
        {
            if(cur->node.find(c) == cur->node.end())
                cur->node[c] = new TrieNode();
            cur = cur->node[c];
        }
        cur->eow=true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c:word)
        {
            if(cur->node.find(c) == cur->node.end())
                return false;
            cur=cur->node[c];
        }
        return cur->eow;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur =root;
        for(char c: prefix)
        {
            if(cur->node.find(c) == cur->node.end())
                return false;
            cur = cur->node[c];
        }
        return true;
    }
};
