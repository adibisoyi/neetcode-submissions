class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row= grid.size(),col=grid[0].size();
        int area=0;
        if(row==0)
            return 0;

        auto bfs = [&](int r, int c){
            int count=1;
            grid[r][c]=0;
            queue<pair<int,int>> q;
            q.push({r,c});
            int dr[4]={-1,1,0,0};
            int dc[4]={0,0,-1,1};

            while(!q.empty())
            {
                auto[i,j]=q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int nr = i+dr[d];
                    int nc = j+dc[d];

                    if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=0;
                        q.push({nr,nc});
                        count++;
                    }
                }
            }
            return count;
        };
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    area = max(area,bfs(i,j));
            }
        }
        return area;

    }
};
