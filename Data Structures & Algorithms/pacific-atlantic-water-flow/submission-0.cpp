class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<int>>& visited)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        
        visited[r][c] = 1;
        for (auto [dr, dc] : dirs) 
        {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc])
            {
                if (heights[nr][nc] >= heights[r][c])
                    dfs(nr, nc, heights, visited);
            } 
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pacificVisited(rows, std::vector<int>(cols, 0));
        vector<vector<int>> atlanticVisited(rows, std::vector<int>(cols, 0));

        for(int i=0;i < rows;i++)
        {
            // Only the top values of pacific ocean i.e. first row
            dfs(i , 0, heights,pacificVisited);
            // Only the right values of atlantic i.e. last coloumn
            dfs(i , cols-1, heights,atlanticVisited);
        }

        for(int i=0;i < cols;i++)
        {
            // Only the top values of pacific ocean i.e. first row
            dfs(0 , i, heights,pacificVisited);
            // Only the bottom values of atlantic i.e. last coloumn
            dfs(rows-1 , i, heights,atlanticVisited);
        }

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};
