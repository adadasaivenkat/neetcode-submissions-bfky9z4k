class Solution {
int dp[105][105];
private:
    int dfs(int r, int c, int &m, int &n, vector<vector<int>>& obstacleGrid){
        if(r>=m || c>=n) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=dfs(r+1,c,m,n,obstacleGrid)+dfs(r,c+1,m,n,obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0; i<105; i++){
            for(int j=0; j<105; j++){
                dp[i][j]=-1;
            }
        }
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        return dfs(0,0,m,n,obstacleGrid);
    }
};