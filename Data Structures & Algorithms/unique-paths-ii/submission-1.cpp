class Solution {
private:
    int dfs(int r, int c, int &m, int &n, vector<vector<int>>& obstacleGrid){
        if(r>=m || c>=n) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==m-1 && c==n-1) return 1;
        return dfs(r+1,c,m,n,obstacleGrid)+dfs(r,c+1,m,n,obstacleGrid);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        return dfs(0,0,m,n,obstacleGrid);
    }
};

/*
General order for recursive/DFS problems:
1. Invalid (failure) cases → return immediately.
2. Success (base) case → return the answer.
3. Memoization check (if using DP).
4. Recursive calls.

Template:
if (invalid)
    return 0;

if (success)
    return 1;

if (dp[state] != -1)
    return dp[state];

return dp[state] = dfs(...);

Why?
Because you should reject impossible states first before deciding you've reached the goal.
For example,
if (r >= m || c >= n) return 0;      // Out of bounds
if (obstacleGrid[r][c] == 1) return 0; // Obstacle
if (r == m-1 && c == n-1) return 1;    // Reached destination
Imagine the destination is an obstacle:
0 0
0 1
If you check the destination first, you'll incorrectly return 1 even though it's blocked.
*/