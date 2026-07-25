class Solution {
int dp[205][205];
private:
    int dfs(int r, int c, int &m, int &n, vector<vector<int>>& grid){
        if(r>=m || c>=n) return INT_MAX;
        if(r==m-1 && c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int down=dfs(r+1,c,m,n,grid);
        int right=dfs(r,c+1,m,n,grid);
        return dp[r][c]=grid[r][c]+min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i<205; i++){
            for(int j=0; j<205; j++){
                dp[i][j]=-1;
            }
        }
        int m=grid.size(),n=grid[0].size();
        return dfs(0,0,m,n,grid);
    }
};