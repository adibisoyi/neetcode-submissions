class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size(),n=grid[0].size();
        if(m==0)
            return 0;

        auto bfs = [&](int row,int col){
            queue<pair<int ,int>> q;
            grid[row][col]='T';
            q.push({row,col});
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};

            while(!q.empty())
            {
                auto[i,j]=q.front();q.pop();

                for(int d=0;d<4;d++)
                {
                    int nr = dr[d]+i;
                    int nc = dc[d]+j;

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1')
                    {
                        grid[nr][nc]='T';
                        q.push({nr,nc});
                    }
                }
            }
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
