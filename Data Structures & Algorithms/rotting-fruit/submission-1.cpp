class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(),col=grid[0].size();
        int fresh=0,time=0;
        queue<pair<int,int>> rotten;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        auto bfs = [&](){
            int size = rotten.size();
            bool flag = false;
            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};

            while(size--)
            {
                auto [i,j]=rotten.front();rotten.pop();
                for(int d=0;d<4;d++)
                {
                    int nr = i+dr[d];
                    int nc = j+dc[d];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        flag=true;
                        fresh--;
                        rotten.push({nr,nc});
                    }
                }
            }
            return flag;
        };
        while(!rotten.empty())
        {
            if(bfs())
                time++;
            else
                break;
        }
        return (fresh==0)?time:-1;
    }
};
