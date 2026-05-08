class TrieNode {
public:
    unordered_map<char,TrieNode*> node;
    bool eow=false;
};
class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string word,int idx,TrieNode* cur)
    {
        if(idx == word.size())
            return cur->eow;

        char c = word[idx];
        if(c != '.')
        {
            if(cur->node.find(c) == cur->node.end())
                return false;
            return dfs(word,idx+1,cur->node[c]);
        }

        for(auto& child : cur->node)
        {
            if(dfs(word,idx+1,child.second))
                return true;
        }
        return false;
    }
public:
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c:word)
        {
            if(cur->node.find(c) == cur->node.end())
                cur->node[c] = new TrieNode();
            cur = cur->node[c];
        }
        cur->eow = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
