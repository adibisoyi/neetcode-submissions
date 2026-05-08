class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==0)
                    q.push({i,j});
        
        auto bfs =[&](){
            int size = q.size();
            bool flag= false;
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};

            while(size--)
            {
                auto [r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int nr = r+dr[d];
                    int nc = c+dc[d];
                    if(nr>=0 && nr<row &&
                        nc>=0 && nc<col &&
                        grid[nr][nc]==INT_MAX)
                        {
                            grid[nr][nc]= grid[r][c]+1;
                            q.push({nr,nc});
                            flag=true;
                        }
                }
            }
            return flag;
        };

        while(!q.empty())
        {
            if(!bfs())
                break;
        }
    }
};
