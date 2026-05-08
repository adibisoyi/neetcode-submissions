class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int row = heights.size();
      int col = heights[0].size();

      queue<pair<int,int>> paciq,atlnq;
      vector<vector<bool>> pac(row,vector<bool>(col,false));
      vector<vector<bool>> atl(row,vector<bool>(col,false));  

      for(int c=0;c<col;c++)
      {
        paciq.push({0,c});
        atlnq.push({row-1,c});
      }

      for(int r=0;r<row;r++)
      {
        paciq.push({r,0});
        atlnq.push({r,col-1});
      }

      auto bfs=[&](queue<pair<int,int>> &q,vector<vector<bool>> &visited){
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        
        while(!q.empty())
        {
            auto[r,c]=q.front();
            q.pop();
            if(visited[r][c])
                continue;
            visited[r][c]=true;
            for(int d=0;d<4;d++)
            {
                int nr = r+dr[d];
                int nc =c+dc[d];

                if(nr>=0 && nr<row &&
                    nc>=0 && nc<col &&
                    !visited[nr][nc] &&
                    heights[nr][nc] >= heights[r][c])
                    {
                        q.push({nr,nc});
                    }
            }
        }
      };

      bfs(paciq,pac);
      bfs(atlnq,atl);
      vector<vector<int>> result;

      for(int i=0;i<row;i++)
      {
        for(int j=0;j<col;j++)
        {
            if((pac[i][j]) && atl[i][j])
                result.push_back({i,j});
        }
      }
      return result;
    }
};
