class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>> &vis,
    int n, int m, int i, int j, int &perimeter){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        perimeter+=4;
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    if(!vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        perimeter+=4;
                    }
                    perimeter-=1;
                }
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int perimeter=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    bfs(grid,vis,n,m,i,j,perimeter);
                }

            }
        }
        return perimeter;
    }
};