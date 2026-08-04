class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 1));

        // for(int i=0;i < m+1;i++) grid[i][0] = 1;
        // for(int j=0;j < n+1;j++) grid[0][j] = 1;

        for(int i= 1;i<m;i++)
        {
            for(int j=1; j <n;j++)
            {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};
