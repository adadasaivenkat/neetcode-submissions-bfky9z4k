class Solution {
private:
    int dfs(int r, int c, int &m, int &n, vector<vector<int>>& grid){
        if(r>=m || c>=n) return INT_MAX;
        if(r==m-1 && c==n-1) return grid[r][c];
        int down=dfs(r+1,c,m,n,grid);
        int right=dfs(r,c+1,m,n,grid);
        return grid[r][c]+min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        return dfs(0,0,m,n,grid);
    }
};