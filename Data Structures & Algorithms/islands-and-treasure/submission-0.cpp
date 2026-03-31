class Solution {
public:
    const int INF=2147483647;
private:
    int bfs(vector<vector<int>>& grid, int n, int m, int i, int j, int dist){
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(grid[r][c]==0) return dist;
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=-1 && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            dist++;
        }
        return grid[i][j];     // return INF;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==INF){
                    grid[i][j]=bfs(grid,n,m,i,j,0);
                }
            }
        }
    }
};
