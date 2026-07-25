class Solution {
private:
    void dfs(int r, int c, int &m, int &n, vector<vector<int>>& grid, int sum, int &minSum){
        if(r>=m || c>=n) return;
        if(r==m-1 && c==n-1){
            minSum=min(minSum,sum+grid[r][c]);
            return;
        }
        dfs(r+1,c,m,n,grid,sum+grid[r][c],minSum);
        dfs(r,c+1,m,n,grid,sum+grid[r][c],minSum);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int minSum=INT_MAX;
        int m=grid.size(),n=grid[0].size();
        dfs(0,0,m,n,grid,0,minSum);
        return minSum;
    }
};