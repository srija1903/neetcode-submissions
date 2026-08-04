class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c)
    {
        int rows = grid.size(),cols = grid[0].size();
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;
        
        grid[r][c] = '0'; // Marking the element as visited
        // 2. Recurse in 4 directions: Down, Up, Right, Left
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;

        int islandCount = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid,i,j);
                }
            }
        }
        return islandCount;
    }
};
