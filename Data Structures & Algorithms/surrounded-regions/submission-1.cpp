class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n= board[0].size();
        if(m==0)
            return;
        
        auto bfs = [&](int row,int col){
            queue<pair<int,int>>q;
            q.push({row,col});
            board[row][col] = 'T';
            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};

            while(!q.empty()){
            auto[i,j]=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int nr = i+dr[d];
                int nc = j+dc[d];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        board[nr][nc] == 'O'){
                    board[nr][nc]='T';
                    q.push({nr,nc});
                }
            
            }
           }
        };
        for(int i=0;i<m;i++)
        {
            if(board[i][0] == 'O') bfs(i,0);
            if(board[i][n-1] == 'O') bfs(i,n-1);
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j] == 'O') bfs(0,j);
            if(board[m-1][j] == 'O') bfs(m-1,j);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='T')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
