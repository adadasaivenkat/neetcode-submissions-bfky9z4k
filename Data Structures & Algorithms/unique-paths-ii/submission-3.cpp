#include<cstring>
class Solution {
int dp[105][105];
private:
    int solve(int r, int c, int n, int m, vector<vector<int>>& obstacleGrid){
        if(r>=n || c>=m) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int down=solve(r+1,c,n,m,obstacleGrid);
        int right=solve(r,c+1,n,m,obstacleGrid);
        return dp[r][c]=down+right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        return solve(0,0,n,m,obstacleGrid);
    }
};