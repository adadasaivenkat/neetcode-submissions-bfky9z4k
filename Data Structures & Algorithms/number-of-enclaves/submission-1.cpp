class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col,
    int dr[], int dc[], int n, int m){
        vis[row][col]=1;
        for(int i=0; i<4; i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(grid,vis,nr,nc,dr,dc,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1 && vis[i][j]==0){
                        dfs(grid,vis,i,j,dr,dc,n,m);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};