class TrieNode{
public:
    unordered_map<char,TrieNode*> node;
    bool eow=false;
    string word="";
};

class Solution {
private:
    TrieNode* root;
    vector<string> answer;
    int col,row;
    void addword(string word)
    {
        TrieNode* cur = root;
        for(char c:word)
        {
            if(cur->node.find(c) == cur->node.end())
                cur->node[c] = new TrieNode();
            cur= cur->node[c];
        }
        cur->eow=true;
        cur->word = word;
    }
    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* cur)
    {
        if(r<0 || c<0 || r>=row || c>=col || board[r][c] =='#')
            return;
        char ch = board[r][c];

        if(cur->node.find(ch) ==cur->node.end())
            return;
        TrieNode* nextnode = cur->node[ch];

        if(nextnode->eow)
        {
            answer.push_back(nextnode->word);
            nextnode->eow = false;
        }

        board[r][c] = '#';

        dfs(board,r+1,c,nextnode);
        dfs(board,r-1,c,nextnode);
        dfs(board,r,c+1,nextnode);
        dfs(board,r,c-1,nextnode);

        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();
        root = new TrieNode();
        for(auto word:words)
            addword(word);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                dfs(board,i,j,root);
            }
        }
        return answer;
    }
};
